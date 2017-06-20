#include <stdlib.h>
#include <string.h>
#include "../portable.h"

void* malloc( size_t nBytes )
{
	return osMemoryAllocate(nBytes);
}

void* realloc( void* aptr, size_t nBytes )
{
	return osMemoryReallocate(aptr, nBytes);
}

void* calloc(
	size_t n __attribute__((unused)),
	size_t s __attribute__((unused)) )
{
	void *ret = malloc( n * s );
	if( ret )
		memset( ret, 0, n * s );

	return ret;
}

void free( void *aptr )
{
	osMemoryFree(aptr);
}

void* _malloc_r( struct _reent* reent __attribute__((unused)),
	size_t size )
{
	return malloc( size );
}

void* _realloc_r( struct _reent* reent __attribute__((unused)),
	void* aptr, size_t size )
{
	return realloc( aptr, size );
}

void* _calloc_r( struct _reent* reent __attribute__((unused)),
	size_t n, size_t s )
{
	return calloc( n, s );
}

void _free_r( struct _reent* reent __attribute__((unused)),
	void *p )
{
	free(p);
}

