#ifndef H7C348E27_D161_4CFC_A27D_FE20CE25B09D
#define H7C348E27_D161_4CFC_A27D_FE20CE25B09D

/*******************************************************************
 * THESE VARIABLES ARE DEFIEND IN THE LINKER SCRIPT
 *******************************************************************/
/* START AND END OF THE TEXT SECITON, IN FLASH*/
__attribute__( (unused) ) extern unsigned int text_start;
__attribute__( (unused) ) extern unsigned int text_end;

/* START AND END OF THE DATA SECITON, IN RAM, AS WELL AS THE LOAD ASSRESS, IN FLASH*/
__attribute__( (unused) ) extern unsigned int data_start;
__attribute__( (unused) ) extern unsigned int data_end;
__attribute__( (unused) ) extern unsigned int data_load;

/* START AND END OF THE BSS SECTION, IN RAM */
__attribute__( (unused) ) extern unsigned int bss_start;
__attribute__( (unused) ) extern unsigned int bss_end;

/* START AND END OF THE MAIN STACK */
__attribute__( (unused) ) extern unsigned int initial_main_stack;
__attribute__( (unused) ) extern unsigned int main_stack_start;
__attribute__( (unused) ) extern unsigned int main_stack_end;

/* START AND END OF THE UNUSED FLASH SECTION */
__attribute__((unused)) extern unsigned int uflash_start;
__attribute__((unused)) extern unsigned int uflash_end;

/* START AND END OF THE HEAP SECTION, IN RAM.
 * THE LINKER WILL AUTOMATICALLY ALLOCATE ALL THE RAM REMAINS AFTER
 * BSS AND DATA TO HEAP */
__attribute__( (unused) ) extern unsigned int heap_start;
__attribute__( (unused) ) extern unsigned int heap_end;

__attribute__( (unused) ) extern void (*init_array_start[])(void);
__attribute__( (unused) ) extern void (*init_array_end[])(void);

__attribute__( (unused) ) extern void (*fini_array_start[])(void);
__attribute__( (unused) ) extern void (*fini_array_start[])(void);


#endif /* H7C348E27_D161_4CFC_A27D_FE20CE25B09D */
