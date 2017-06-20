/***************************************************************
 * RTOS Port for Cortex-M3
 *
 * Some functions are defined in asmFunctions.s for convenience
 * to write in assembly language.
 ***************************************************************/

#include "../portable.h"
#include "../ldscripts/magic_variables.h"

/* a complete Cortex-M3 stack frame */
typedef struct
{
	/* the following registers are pushed onto the stack by
	 * the operating system context switcher */
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;

	/* on exception entry, the following registers are
	 * automatically pushed onto the stack by the processor */
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t PSR;
} StackFrame_t;

/* this value is popped into the PSR when the thread is first loaded */
#define INITIAL_PSR		( 0x01000000UL )

/* register to set PendSV */
#define PENDSV_REG			( *((volatile uint32_t*) 0xE000ED04) )

/* register to enable systick */
#define SYSTICK_REG		( *((volatile uint32_t*) 0xE000E010) )

/* bit to set to set PendSV */
#define PENDSV_SET			( 1 << 28 )

/* bit to set to enable SYSTICK */
#define SYSTICK_SET  		( 1 << 0 )

/* the idle thread */
__attribute__((noreturn))
void port_idle( void )
{
	for( ; ; )
		__asm volatile( "WFI" );
}

void port_startKernel( void )
{
	/* enable the systick. The systick have to be configured earlier */
	SYSTICK_REG |= SYSTICK_SET;

	/* call the assembly function to prepare the processor for multithreading */
	__asm volatile( "SVC 0\n\t" );
}

void port_yield( void )
{
	/* set PENDSV to indicate yield request. Context switch will happen after
	 * have been served */
	PENDSV_REG |= PENDSV_SET;
}

void port_heapInit( void )
{
	/* these values are defined in the linker script */
	MemoryBlock_t* block = (MemoryBlock_t*) ( &heap_start );
	osCounter_t size = (osByte_t*) ( &heap_end ) - (osByte_t*) ( &heap_start );

	/* create the initial heap block */
	memory_blockInit( block, size );
	memory_blockInsertToHeap( block );
}

/* makes a fake context on the thread's stack to initialize the registers to the
 * right values when the thread is first loaded into the processor */
osByte_t*
port_makeFakeContext( osByte_t* stack, osCounter_t stackSize, osCode_t code, const void* argument )
{
	/* stack grows to smaller addresses (stack growth is negative on Cortex-M),
	 * get the address of the first stack frame */
	StackFrame_t* frame = (StackFrame_t*)( stack + stackSize - sizeof(StackFrame_t) );

	/* fill the frame */
	/* when calling a single parameter function, the compiler will assume R0 holds the parameter */
	frame->R0 = (uint32_t) argument;

	/* when a function returns, the compiler will generate a BX LR instruction and jump to the
	 * address in LR.
	 * Put the address of the function here that needs to be called upon thread return */
	frame->LR = (uint32_t) ( threadReturnHook );
	frame->PC = (uint32_t) code;
	frame->PSR =(uint32_t) INITIAL_PSR;

	return (osByte_t*) frame;
}

