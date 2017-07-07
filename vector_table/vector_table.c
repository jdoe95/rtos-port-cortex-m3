#include <stdint.h>
#include <stddef.h>
#include "../ldscripts/magic_variables.h"

#define WEAK 				__attribute__( (weak) )
#define INTERRUPT 			__attribute__( (interrupt) )
#define ALIAS( SYMBOL ) 	__attribute__( ( alias(SYMBOL) ) )
#define SECTION( SYMBOL ) 	__attribute__( ( section( SYMBOL )))

WEAK INTERRUPT void DefaultIRQHandler( void );
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void Reset_Handler( void ); 				/* Reset */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void NMI_Handler( void ); 					/* Non maskable interrupt. The RCC Clock Security System is linked to the NMI vector */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void HardFault_Handler( void ); 			/* All class of fault */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void MemManage_Handler( void ); 			/* Memory management */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void BusFault_Handler( void ); 			/* Prefetch fault, memory access fault */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void UsageFault_Handler( void ); 			/* Undefined instruction or illegal state */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void SVC_Handler( void ); 					/* System service call via SWI instruction */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DebugMon_Handler( void ); 			/* Debug Monitor */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void PendSV_Handler( void ); 				/* Pendable request for system service */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void SysTick_Handler( void ); 			/* System tick timer */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void WWDG_IRQHandler( void ); 			/* Window watchdog interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void PVD_IRQHandler( void ); 				/* PVD through EXTI line detection interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TAMPER_IRQHandler( void ); 			/* Tamper interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void RTC_IRQHandler( void ); 				/* RTC global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void FLASH_IRQHandler( void ); 			/* Flash global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void RCC_IRQHandler( void ); 				/* RCC global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI0_IRQHandler( void ); 			/* EXTI line 0 interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI1_IRQHandler( void ); 			/* EXTI line 1 interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI2_IRQHandler( void ); 			/* EXTI line 2 interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI3_IRQHandler( void ); 			/* EXTI line 3 interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI4_IRQHandler( void ); 			/* EXTI line 4 interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel1_IRQHandler( void ); 	/* DMA1 channel1 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel2_IRQHandler( void ); 	/* DMA1 channel2 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel3_IRQHandler( void ); 	/* DMA1 channel3 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel4_IRQHandler( void ); 	/* DMA1 channel4 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel5_IRQHandler( void ); 	/* DMA1 channel5 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel6_IRQHandler( void ); 	/* DMA1 channel6 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA1_Channel7_IRQHandler( void ); 	/* DMA1 channel7 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void ADC1_2_IRQHandler( void ); 			/* ADC1 and ADC2 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN1_TX_IRQHandler( void ); 			/* USB high priority or CAN TX interrupts */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN1_RX0_IRQHandler( void ); 		/* USB low priority or CAN RX0 interrupts */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN1_RX1_IRQHandler( void ); 		/* CAN RX1 interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN1_SCE_IRQHandler( void ); 		/* CAN SCE interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI9_5_IRQHandler( void ); 			/* EXTI line 9~5 interrupts */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM1_BRK_IRQHandler( void ); 		/* TIM1 Break interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM1_UP_IRQHandler( void ); 			/* TIM1 update interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM1_TRG_COM_IRQHandler( void ); 	/* TIM1 Trigger and commutation interrupts */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM1_CC_IRQHandler( void ); 			/* TIM1 capture compare interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM2_IRQHandler( void ); 			/* TIM2 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM3_IRQHandler( void ); 			/* TIM3 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM4_IRQHandler( void ); 			/* TIM4 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void I2C1_EV_IRQHandler( void ); 			/* I2C1 event interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void I2C1_ER_IRQHandler( void ); 			/* I2C1 error interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void I2C2_EV_IRQHandler( void ); 			/* I2C2 event interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void I2C2_ER_IRQHandler( void ); 			/* I2C2 error interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void SPI1_IRQHandler( void ); 			/* SPI1 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void SPI2_IRQHandler( void ); 			/* SPI2 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void USART1_IRQHandler( void ); 			/* USART1 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void USART2_IRQHandler( void ); 			/* USART2 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void USART3_IRQHandler( void ); 			/* USART3 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void EXTI15_10_IRQHandler( void ); 		/* EXTI line 15~10 interrupts */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void RTC_Alarm_IRQHandler( void ); 		/* RTC alarm through EXTI line interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void OTG_FS_WKUP_IRQHandler( void );		/* USB wake up from suspended through EXTI line interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM5_IRQHandler( void ); 			/* TIM5 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void SPI3_IRQHandler( void ); 			/* SPI3 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void UART4_IRQHandler( void ); 			/* UART4 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void UART5_IRQHandler( void ); 			/* UART5 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM6_IRQHandler( void ); 			/* TIM6 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void TIM7_IRQHandler( void ); 			/* TIM7 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA2_Channel1_IRQHandler( void ); 	/* DMA2 channel1 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA2_Channel2_IRQHandler( void ); 	/* DMA2 channel2 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA2_Channel3_IRQHandler( void ); 	/* DMA2 channel3 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA2_Channel4_IRQHandler( void ); 	/* DMA2 channel4~5 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void DMA2_Channel5_IRQHandler( void ); 	/* DMA2 channel4~5 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void ETH_WKUP_IRQHandler( void ); 		/* TIM8 break interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN2_TX_IRQHandler( void ); 			/* TIM8 update interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN2_RX0_IRQHandler( void ); 		/* TIM8 trigger and commutation interrupts */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN2_RX1_IRQHandler( void ); 		/* TIM8 capture compare interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void CAN2_SCE_IRQHandler( void ); 		/* ADC3 global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void OTG_FS_IRQHandler( void ); 			/* SDIO global interrupt */
WEAK INTERRUPT ALIAS( "DefaultIRQHandler" )void ETH_IRQHandler( void ); 				/* SDIO global interrupt */

void DefaultIRQHandler( void ){
	__asm volatile( "BKPT 0\n\t" );
}

SECTION( ".vector_table" ) uint32_t VectorTable[] = {
		(uint32_t) &initial_main_stack,
		(uint32_t) Reset_Handler + 1,
		(uint32_t) NMI_Handler,
		(uint32_t) HardFault_Handler,
		(uint32_t) MemManage_Handler,
		(uint32_t) BusFault_Handler,
		(uint32_t) UsageFault_Handler,
		0,
		0,
		0,
		0,
		(uint32_t) SVC_Handler,
		(uint32_t) DebugMon_Handler,
		0,
		(uint32_t) PendSV_Handler,
		(uint32_t) SysTick_Handler,
		(uint32_t) WWDG_IRQHandler,
		(uint32_t) PVD_IRQHandler,
		(uint32_t) TAMPER_IRQHandler,
		(uint32_t) RTC_IRQHandler,
		(uint32_t) FLASH_IRQHandler,
		(uint32_t) RCC_IRQHandler,
		(uint32_t) EXTI0_IRQHandler,
		(uint32_t) EXTI1_IRQHandler,
		(uint32_t) EXTI2_IRQHandler,
		(uint32_t) EXTI3_IRQHandler,
		(uint32_t) EXTI4_IRQHandler,
		(uint32_t) DMA1_Channel1_IRQHandler,
		(uint32_t) DMA1_Channel2_IRQHandler,
		(uint32_t) DMA1_Channel3_IRQHandler,
		(uint32_t) DMA1_Channel4_IRQHandler,
		(uint32_t) DMA1_Channel5_IRQHandler,
		(uint32_t) DMA1_Channel6_IRQHandler,
		(uint32_t) DMA1_Channel7_IRQHandler,
		(uint32_t) ADC1_2_IRQHandler,
		(uint32_t) CAN1_TX_IRQHandler,
		(uint32_t) CAN1_RX0_IRQHandler,
		(uint32_t) CAN1_RX1_IRQHandler,
		(uint32_t) CAN1_SCE_IRQHandler,
		(uint32_t) EXTI9_5_IRQHandler,
		(uint32_t) TIM1_BRK_IRQHandler,
		(uint32_t) TIM1_UP_IRQHandler,
		(uint32_t) TIM1_TRG_COM_IRQHandler,
		(uint32_t) TIM1_CC_IRQHandler,
		(uint32_t) TIM2_IRQHandler,
		(uint32_t) TIM3_IRQHandler,
		(uint32_t) TIM4_IRQHandler,
		(uint32_t) I2C1_EV_IRQHandler,
		(uint32_t) I2C1_ER_IRQHandler,
		(uint32_t) I2C2_EV_IRQHandler,
		(uint32_t) I2C2_ER_IRQHandler,
		(uint32_t) SPI1_IRQHandler,
		(uint32_t) SPI2_IRQHandler,
		(uint32_t) USART1_IRQHandler,
		(uint32_t) USART2_IRQHandler,
		(uint32_t) USART3_IRQHandler,
		(uint32_t) EXTI15_10_IRQHandler,
		(uint32_t) RTC_Alarm_IRQHandler,
		(uint32_t) OTG_FS_WKUP_IRQHandler,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		(uint32_t) TIM5_IRQHandler,
		(uint32_t) SPI3_IRQHandler,
		(uint32_t) UART4_IRQHandler,
		(uint32_t) UART5_IRQHandler,
		(uint32_t) TIM6_IRQHandler,
		(uint32_t) TIM7_IRQHandler,
		(uint32_t) DMA2_Channel1_IRQHandler,
		(uint32_t) DMA2_Channel2_IRQHandler,
		(uint32_t) DMA2_Channel3_IRQHandler,
		(uint32_t) DMA2_Channel4_IRQHandler,
		(uint32_t) DMA2_Channel5_IRQHandler,
		(uint32_t) ETH_IRQHandler,
		(uint32_t) ETH_WKUP_IRQHandler,
		(uint32_t) CAN2_TX_IRQHandler,
		(uint32_t) CAN2_RX0_IRQHandler,
		(uint32_t) CAN2_RX1_IRQHandler,
		(uint32_t) CAN2_SCE_IRQHandler,
		(uint32_t) OTG_FS_IRQHandler
};
