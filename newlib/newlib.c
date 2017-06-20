#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>

/* error handling */
#undef errno
extern int errno;

void on_exit();
void on_write( const char* ptr, int len );

/* stubs for newlib. See: https://sourceware.org/newlib/libc.html#Stubs */
void _exit( int );
int _close( int );
int _execve( char*, char**, char** );
int fork( void );
int fstat( int, struct stat* );
int getpid( void );
int isatty( int );
int kill( int, int );
int link( const char*, const char* );
off_t lseek( int, off_t, int );
int open( const char*, int, int );
int read( int, void*, size_t );
void* sbrk( ptrdiff_t );
int stat( const char*, struct stat* );
clock_t times( struct tms* );
int _unlink( char* );
int wait( int* );

/* _exit:
 * Exit a program without cleaning up files.
 */
void
_exit( int code __attribute__((unused)) )
{
	on_exit();

	for( ; ; )
		;
}

/* close:
 * Close a file.
 */
int
_close( int fildes __attribute__((unused)) )
{
	return -1;
}

/* environ:
 * a pointer to a list of environemnt variables and their values.
 * For a minimal rnvironment, this empty list is adequate.
 */
char *__env[1] = { 0 };
char **environ = __env;

/* execve:
 * Transfer control to a new process.
 */
int
_execve(
	char *name __attribute__((unused)),
	char **argv __attribute__((unused)),
	char **env __attribute__((unused)) )
{
	errno = ENOMEM;
	return -1;
}

/* fork:
 * Create a new process.
 */
int
fork(void)
{
	errno = EAGAIN;
	return -1;
}

/* fstat:
 * status of an open file.
 */
int
fstat(
	int file __attribute__((unused)),
	struct stat *st __attribute__((unused)) )
{
	st->st_mode = S_IFCHR;
	return 0;
}

/* getpid:
 * Process-ID. This is sometimes used to generate strings unlikely
 * to conflict with other processes.
 */
int
getpid( void )
{
	return 1;
}

/* isatty:
 * Query whether output stream is a terminal.
 */
int
isatty( int file __attribute__((unused)) )
{
	return 1;
}

/* kill:
 * Send a signal.
 */
int
kill(
	int pid __attribute__((unused)),
	int sig __attribute__((unused)) )
{
	errno = EINVAL;
	return -1;
}

/* link:
 * Establish a new name for an existing file.
 */
int
link(
	const char *old __attribute__((unused)),
	const char *new __attribute__((unused)) )
{
	errno = EMLINK;
	return -1;
}

/* lseek:
 * Set a position in a file.
 */
off_t
lseek(
	int file __attribute__((unused)),
	off_t pos __attribute__((unused)),
	int whence __attribute__((unused)) )
{
	return 0;
}

/* open:
 * Open a file.
 */
int
open(
	const char* name __attribute__((unused)),
	int flags __attribute__((unused)),
	int mode __attribute__((unused)) )
{
	return -1;
}

/* read:
 * Read from a file.
 */
int
read(
	int file __attribute__((unused)),
	void *ptr __attribute__((unused)),
	size_t len __attribute__((unused)) )
{
	return 0;
}

/* sbrk:
 * Increase program data space.
 */
void*
sbrk( ptrdiff_t incr __attribute__((unused)) )
{
#ifdef _DEBUG_
	__asm volatile( "BKPT 0\n\t" );
#endif
	return NULL;
}


/* stat:
 * Status of a file (by name).
 */
int
stat(
	const char *file __attribute__((unused)),
	struct stat* st __attribute__((unused)) )
{
	st->st_mode = S_IFCHR;
	return 0;
}

/* times:
 * Timing information for current process.
 */
clock_t
times( struct tms *buf __attribute__((unused)) )
{
	return -1;
}

/* unlink:
 * Remove a file's directory entry
 */
int _unlink( char *name __attribute__((unused)) )
{
	errno = ENOENT;
	return -1;
}

/* wait:
 * Wait for a child process.
 */
int wait( int *status __attribute__((unused)) )
{
	errno = ECHILD;
	return -1;
}

int _write(
	int file __attribute__((unused)),
	const char* ptr,
	int len )
{
	on_write( ptr, len );
	return len;
}

__attribute__((weak))
void on_write(
	const char *ptr __attribute__((unused)),
	int len __attribute__((unused)) )
{}

__attribute__((weak)) void on_exit( void )
{}
