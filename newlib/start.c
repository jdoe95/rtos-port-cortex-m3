#include <stdlib.h>
#include <stdint.h>
#include "../portable.h"
#include "../ldscripts/magic_variables.h"

static __inline__ void initialize_data( unsigned int * load, unsigned int * begin, unsigned int * end );
static __inline__ void initialize_bss( unsigned int * begin, unsigned int * end );
static __inline__ void run_init_array( void );
static __inline__ void run_fini_array( void );

void init_before_os();
void init_before_main();

extern int main( void );

char main_stack[MAIN_STACK_SIZE] __attribute__(( section(".main_stack") ));

INTERRUPT
void OS_RESET_HANDLER_NAME( void ) {

	// initialize the sections
	initialize_data( &data_load, &data_start, &data_end );
	initialize_bss( &bss_start, &bss_end );

	// initializations that should be done before starting the operating system
	init_before_os();

	// initialize operating system
	osInit();

	// run C++ static object constructors after osInit in case OS API is called
	run_init_array();

	// initializations that should be done before starting the main thread
	init_before_main();

	osThreadCreate( 0, (osCode_t)main, 1024, NULL );

	// start the operating system
	osStart();

	// run C++ static object destruction functions (this should never happen if
	// osStart works properly )
	run_fini_array();
}

extern int main( void );

static __inline__ void
initialize_data( unsigned int * load, unsigned int * begin, unsigned int * end ){
	unsigned int * p = begin;
	while( p < end )
		*p++ = *load++;
}

static __inline__ void
initialize_bss( unsigned int * begin, unsigned int * end ) {
	unsigned int * p = begin;
	while( p < end )
		*p++ = 0;
}

static __inline__ void
run_init_array( void ) {
	int count = init_array_end - init_array_start;
	int i = 0;
	for( ; i < count; i++ )
		init_array_start[i]();
}

static __inline__ void
run_fini_array( void ) {
	int count = fini_array_start - fini_array_start;
	int i = count;
	for( ; i > 0; i-- )
		fini_array_start[i - 1]();
}

__attribute__((weak)) void init_before_os( void )
{}

__attribute__((weak)) void init_before_main( void )
{}

