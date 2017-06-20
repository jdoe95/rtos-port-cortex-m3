/***************************************************************
 * RTOS CONFIGURATION FILE
 *
 * AUTHOR BUYI YU
 *  1917804074@qq.com
 *
 * (C) 2017
 *
 * 	You should have received an open source user license.
 * 	ABOUT USAGE, MODIFICATION, COPYING, OR DISTRIBUTION, SEE LICENSE.
 ***************************************************************/
#ifndef H87CF2F74_D12E_4076_BECA_BC25FAD52A01
#define H87CF2F74_D12E_4076_BECA_BC25FAD52A01

/* compiler */
#define INLINE 			static __inline__ __attribute__((always_inline))
#define NORETURN		__attribute__((noreturn))
#define INTERRUPT		__attribute__((interrupt))

/* miscellaneous */
#define MEMORY_ALIGNMENT 				(4)
#define IDLE_THREAD_STACK_SIZE 			(84)
#define TIMER_THREAD_STACK_SIZE 		(1024)
#define OS_TICK_HANDLER_NAME 			SysTick_Handler
#define OS_RESET_HANDLER_NAME			Reset_Handler
#define MAIN_THREAD_PRIO				0
#define MAIN_THREAD_STACK				1024
#define MAIN_STACK_SIZE					1024

#ifdef _DEBUG_
#define OS_ASSERT( cond ) \
	if( ! (cond) ) \
		__asm volatile( "BKPT 0\n\t" );
#endif

#endif /* H87CF2F74_D12E_4076_BECA_BC25FAD52A01 */
