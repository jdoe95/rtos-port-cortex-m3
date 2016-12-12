
	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.thumb

/***********************************************************************/
	.global port_disableInterrupts
	.section .text.port_disableInterrupts
	.type port_disableInterrupts, %function
port_disableInterrupts:
	DSB
	ISB
	CPSID I
	BX LR
	.size port_disableInterrupts, .-port_disableInterrupts

/***********************************************************************/
	.global port_enableInterrupts
	.section .text.port_enableInterrupts
	.type .port_enableInterrupts, %function
port_enableInterrupts:
	DSB
	ISB
	CPSIE I
	BX LR
	.size port_enableInterrupts, .-port_enableInterrupts

/***********************************************************************/
	.global PendSV_Handler
	.section .text.PendSV_Handler
	.type PendSV_Handler, %function
PendSV_Handler:
	CPSID I
	LDR R0, =contextNoSave
	LDR R1, [R0]
	CBNZ R1, PendSV_Handler_1

	///////////////////////////////////////////////////////
	LDR R0, =currentThread // & currentThread
	LDR R0, [R0] // currentThread, & currentThread->PSP
	MRS R12, PSP
	STMDB R12!, {R4-R11} // save context
	STR R12, [R0] // R12 -> currentThread->PSP

PendSV_Handler_1: // context switch nosave
	LDR R0, =nextThread // & nextThread
	LDR R0, [R0] // nextReadyThread, & nextReadyThread->PSP
	LDR R12, [R0] // nextReadyThread->PSP -> R12
	LDMIA R12!, {R4-R11} // load context
	MSR PSP, R12

	LDR R1, =currentThread // & currentThread
	STR R0, [R1] // currentThread = nextReadyThread

	CPSIE I
	BX LR
	///////////////////////////////////////////////////////
	.size PendSV_Handler, .-PendSV_Handler

/***********************************************************************/
	.section .text.loadFirstThread
	.type loadFirstThread, %function
loadFirstThread:
	CPSID I
	LDR R0, =initial_main_stack
	MSR MSP, R0
	LDR R0, =currentThread
	LDR R0, [R0]
	LDR R12, [R0]
	LDMIA R12!, {R4-R11}
	MSR PSP, R12
	LDR LR, =0xFFFFFFFD
	CPSIE I
	BX LR
	.size loadFirstThread, .-loadFirstThread

/***********************************************************************/
	.global asmLoadFirstThread
	.section .text.asmLoadFirstThread
	.type asmLoadFirstThread, %function
asmLoadFirstThread:
	DSB
	ISB
	SVC 0
	BX LR
	.size asmLoadFirstThread, .-asmLoadFirstThread

/***********************************************************************/
.global  SVC_Handler
	.section .text.SVC_Handler
	.type SVC_Handler, %function
SVC_Handler:
	TST LR, #0x4
	ITE EQ
	MRSEQ R1, MSP
	MRSNE R1, PSP
	LDR R3, [R1, #24]
	LDRB R2, [R3, #-2]
	LDR R3, =SVCTable
	LDR R3, [R3, R2, LSL #2]
	BX R3
	.size SVC_Handler, .-SVC_Handler

/***********************************************************************/
	.global SVCTable
	.section .svc_table, "a", %progbits
	.type SVCTable, %object
SVCTable:
	.word loadFirstThread
	.size SVCTable, .-SVCTable

	.end

