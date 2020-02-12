/*

*/
// null_main.c -- null system driver to aid porting efforts

#include <errno.h>
#include <stdio.h>
#include "../qcommon/qcommon.h"

int			sys_curtime;


//===================================================================


void Sys_Error (char *error, ...) {
	va_list		argptr;

	printf ("Sys_Error: ");	
	va_start (argptr,error);
	vprintf (error,argptr);
	va_end (argptr);
	printf ("\n");

	exit (1);
}

void Sys_Quit (void) {
	exit (0);
}

char *Sys_GetClipboardData( void ) {
	return NULL;
}

int		Sys_Milliseconds (void) {
	return 0;
}

FILE	*Sys_FOpen(const char *ospath, const char *mode) {
	return fopen( ospath, mode );
}

void	Sys_Mkdir (char *path) {
}

void	Sys_Init (void) {
}


void main (int argc, char **argv) {
	Com_Init (argc, argv);

	while (1) {
		Com_Frame( );
	}
}


