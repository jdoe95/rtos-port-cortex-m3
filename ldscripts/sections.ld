ENTRY( Reset_Handler );

SECTIONS
{
	/******************************************************************
	 * THE VECTOR TABLE
	 * The vector table must remain in the correct position in flash.
	 ******************************************************************/
	.vector : ALIGN(4)
	{
		KEEP( *(.vector_table) )
	} >INTERNAL_FLASH
	
	/******************************************************************
	 * THE SVC TABLE
	 ******************************************************************/
	 .svc_table : ALIGN(4)
	 {
	 	KEEP( *(.svc_table) )
	 } > INTERNAL_FLASH
	
	/******************************************************************
	 * THE TEXT SECTION
	 ******************************************************************/
	.text : ALIGN(4)
	{
		text_start = .;
		
		/* C++ static object initialization array */
		init_array_start = .;
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		init_array_end = .;
		
		/* C++ static object destruction array */
		fini_array_start = .;
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		fini_array_end = .;
		
		KEEP(*(.init))
		KEEP(*(.fini))
		
		/* text section */
		*(.text .text.*)
		*(.rodata .rodata.* .constdata .constdata.*)
		
		/* C++ virtual table */
		*(vtable)
		
		/* C++ software exception frames */
		KEEP(*(.eh_frame*))
        
		text_end = .;
		
	} >INTERNAL_FLASH
	
	/******************************************************************
	 * EXCEPTION INDEX AND EXCEPTION TABLE
	 ******************************************************************/
	.ARM.exidx : ALIGN(4)
	{
		/* C++ exception index */
		
		__exidx_start = .;
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
		__exidx_end = .;
		
	} >INTERNAL_FLASH
	
	.ARM.extab : ALIGN(4)
	{
		/* C++ exception table */
		
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} >INTERNAL_FLASH
	
	/******************************************************************
	 * THE MAIN STACK
	 ******************************************************************/
	
	.main_stack (NOLOAD): ALIGN(4)
	{
		/* The main stack */
		
	 	main_stack_start = .;
	 	
		KEEP(*(*.main_stack))
		
		main_stack_end = .;
		initial_main_stack = .;
		__stack = .;
		
	} >INTERNAL_SRAM
	
	/******************************************************************
	 * THE BSS SECTION
	 ******************************************************************/
	.bss (NOLOAD) : ALIGN(4)
	{
		bss_start = .;
		*(.bss .bss.*)
		*(COMMON)
		bss_end = .;	
	} >INTERNAL_SRAM
	 
	 /******************************************************************
	 * THE DATA SECTION
	 ******************************************************************/
	.data : ALIGN(4)
	{
		data_start = .	;
		*(.data .data.*)
		data_end = .;
	} >INTERNAL_SRAM AT>INTERNAL_FLASH
	data_load = LOADADDR(.data);
	
	/******************************************************************
	 * THE OPERATING SYSTEM HEAP
	 ******************************************************************/
	.osmem (NOLOAD) : ALIGN(4)
	{
		/* heap used by operating system memory */
		
		heap_start = . ;
		. = ORIGIN(INTERNAL_SRAM) + LENGTH(INTERNAL_SRAM);
		heap_end = .;
	} >INTERNAL_SRAM
	
	/******************************************************************
	 * UNUSED FLASH MEMORY
	 ******************************************************************/
	 .uflash : ALIGN(4)
	 {
	 	uflash_start = . ;
	 	. = ORIGIN(INTERNAL_FLASH) + LENGTH(INTERNAL_FLASH);
	 	uflash_end = . ;
	 } >INTERNAL_FLASH
	
	/******************************************************************
	 * DEBUG SYMBOLS
	 ******************************************************************/
	.stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }    
}
