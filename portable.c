#include "../portable.h"
#include <magic_variables.h>
#include <driver.h>

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
#define PENDSV_SET			( 1 << 28 )

extern void asmLoadFirstThread( void );

void
port_startKernel( void )
{
	// set the NVIC priority grouping
	// 4 bits all used for preemption
	NVIC_SetPriorityGrouping( 3 );

	// set the Systick priority to be the highest
	// set the PendSV priority to be the lowest
	NVIC_SetPriority( SysTick_IRQn, 0);
	NVIC_SetPriority( PendSV_IRQn, 15 );
	NVIC_SetPriority( SVCall_IRQn, 0);

	// configure the systick interrupt to be 100Hz based on the frequency
	// enable interrupt from the systick control
	SysTick_Config( 8000000 / 100 / 8 );

	// other initializations moved to user space
	asmLoadFirstThread();
}

void
port_yield( void )
{
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
port_makeFakeContext( osByte_t* stack, osCounter_t stackSize, osCode_t code, void* argument )
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

