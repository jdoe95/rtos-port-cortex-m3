#include "../portable.h"
#include <magic_variables.h>

typedef struct {
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t PSR;
} StackFrame_t;

#define INITIAL_PSR			( 0x01000000UL )
#define PENDSV_REG			( *((volatile uint32_t*) 0xE000ED04) )
#define SYSTICK_REG			( *((volatile uint32_t*) 0xE000E010) )
#define PENDSV_SET			( 1 << 28 )
#define SYSTICK_SET			( 1 << 0 )

uint32_t contextNoSave;

extern void asmLoadFirstThread( void );

void
port_startKernel( void )
{
	SYSTICK_REG |= SYSTICK_SET;
	asmLoadFirstThread();
}

void
port_yield( void )
{
	contextNoSave = 0;
	PENDSV_REG |= PENDSV_SET;
}

void
port_loadNewThread( void )
{
	contextNoSave = 1;
	PENDSV_REG |= PENDSV_SET;
}

void
port_heapInit( void )
{
	MemoryBlock_t* block = (MemoryBlock_t*)( & heap_start );
	osCounter_t size = (osByte_t*)( & heap_end ) - (osByte_t*)( & heap_start );

	memory_blockInit( block, size );
	memory_blockInsertToHeap( block );
}

osByte_t*
port_makeFakeContext( osByte_t* stack, osCounter_t stackSize, osCode_t code, const void* argument )
{
	osByte_t* start = stack + stackSize;
	StackFrame_t* stackFrame = (StackFrame_t*) start;

	stackFrame--;
	stackFrame->PSR = INITIAL_PSR;
	stackFrame->PC = (uint32_t) code;
	stackFrame->LR = (uint32_t) (threadReturnHook);
	stackFrame->R0 = (uint32_t) argument;
	return (osByte_t*) stackFrame;
}

void
SysTick_Handler( void )
{
	osTickHandler();
}

osBool_t
port_isInThread( void )
{
	return true;
}
