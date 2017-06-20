
	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.thumb

/***********************************************************************/
	.global port_disableInterrupts
	.section .text.port_disableInterrupts
	.type port_disableInterrupts, %function
port_disableInterrupts:
	// make sure ICACHE and DCACHE are exhanusted ( all possible write operations are done )
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
	CPSIE I
	BX LR
	.size port_enableInterrupts, .-port_enableInterrupts

/***********************************************************************/
	.global PendSV_Handler
	.section .text.PendSV_Handler
	.type PendSV_Handler, %function
PendSV_Handler:
	// make sure ICACHE and DCACHE are exhanusted ( all possible write operations are done )
	DSB
	ISB
	CPSID I

	// context saving stage
	// available registers(whose value are saved): R0-R3, R12, PC, PSR
	///////////////////////////////////////////////////////
	LDR R0, =currentThread // & currentThread
	LDR R1, [R0] // currentThread, & currentThread->PSP
	MRS R12, PSP
	STMDB R12!, {R4-R11} // save context
	STR R12, [R1] // R12 -> currentThread->PSP
	///////////////////////////////////////////////////////
	// context saving stage complete
	// available registers(whose value are saved): R0-R12, PC, PSR

	// context restoring stage
	///////////////////////////////////////////////////////
	LDR R2, =nextThread // & nextThread
	LDR R3, [R2] // nextReadyThread, & nextReadyThread->PSP
	LDR R12, [R3] // nextReadyThread->PSP -> R12
	LDMIA R12!, {R4-R11} // load context
	MSR PSP, R12
	///////////////////////////////////////////////////////
	// context restoring stage complete
	// available registers(whose value are saved): R0-R3, R12, PC, PSR

	// post context switch maintainance
	STR R3, [R0] // currentThread = nextReadyThread
	///////////////////////////////////////////////////////
	CPSIE I
	BX LR

	.size PendSV_Handler, .-PendSV_Handler

/***********************************************************************/
	.section .text.loadFirstThread
	.type loadFirstThread, %function
loadFirstThread:
	// make sure ICACHE and DCACHE are exhanusted ( all possible write operations are done )
	DSB
	ISB
	CPSID I

	// clear main stack
	// available registers R0-R12, LR, PC, PSR
	LDR R0, =initial_main_stack
	MSR MSP, R0
	///////////////////////////////////////////////////////

	// context restoring stage
	///////////////////////////////////////////////////////
	LDR R0, =currentThread // & currentThread
	LDR R0, [R0] // currentThread, & currentThread->PSP
	LDR R12, [R0] // currentThread->PSP -> R12
	LDMIA R12!, {R4-R11} // load context
	MSR PSP, R12
	///////////////////////////////////////////////////////
	// context restoring stage complete
	// available registers: R0-R3, R12, LR, PC, PSR

	// set EXC_RETURN to put processor into thread mode
	LDR LR, =0xFFFFFFFD
	CPSIE I
	BX LR

	.size loadFirstThread, .-loadFirstThread

/***********************************************************************/
.global  SVC_Handler
	.section .text.SVC_Handler
	.type SVC_Handler, %function
SVC_Handler:
	// extract the SVC number from the instruction in FLASH
	// get the PC to the instruction
	TST LR, #0x4 // is PC in process stack or main stack?
	ITE EQ
	MRSEQ R1, MSP // in main stack
	MRSNE R1, PSP // in proces stack
	LDR R3, [R1, #24] // find the SVC instruction
	LDRB R2, [R3, #-2] // load the SVC number in the instruction
	LDR R3, =SVCTable
	LDR R3, [R3, R2, LSL #2] // load SVC handler to the SVC number
	BX R3 // jump to the svc handler
	.size SVC_Handler, .-SVC_Handler

/***********************************************************************/
	.global SVCTable
	.section .svc_table, "a", %progbits
	.type SVCTable, %object
SVCTable:
	.word loadFirstThread
	.size SVCTable, .-SVCTable

	.end

