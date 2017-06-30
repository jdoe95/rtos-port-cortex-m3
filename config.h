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

#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>

/* OS types  */
typedef bool					osBool_t;
typedef uintptr_t				osHandle_t;
typedef uint32_t		 		osCounter_t;
typedef uint8_t 				osByte_t;
typedef void* 					osCode_t;

/* miscellaneous */
#define OS_PRIO_LOWEST					UINT32_MAX /* largest value of osCounter_t */
#define MEMORY_ALIGNMENT 				(4)
#define IDLE_THREAD_STACK_SIZE 		(128)
#define TIMER_THREAD_STACK_SIZE 		(1024)
#define OS_TICK_HANDLER_NAME 			SysTick_Handler
#define OS_RESET_HANDLER_NAME			Reset_Handler
#define MAIN_STACK_SIZE				(1024)

/* compiler */
#define INLINE 		static __inline__ __attribute__((always_inline))
#define NORETURN		__attribute__((noreturn))
#define INTERRUPT		__attribute__((interrupt))

#ifdef _DEBUG_
#define OS_ASSERT( cond ) \
	if( ! (cond) ) \
		__asm volatile( "BKPT 0\n\t" );
#endif

#endif /* H87CF2F74_D12E_4076_BECA_BC25FAD52A01 */
