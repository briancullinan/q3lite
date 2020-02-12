/*

*/

#include "../qcommon/q_shared.h"
#include "../qcommon/qcommon.h"

#ifndef DEDICATED
#ifdef USE_LOCAL_HEADERS
#	include "SDL_version.h"
#else
#	include <SDL_version.h>
#endif

// Require a minimum version of SDL
#define MINSDL_MAJOR 2
#define MINSDL_MINOR 0
#if SDL_VERSION_ATLEAST( 2, 0, 5 )
#define MINSDL_PATCH 5
#else
#define MINSDL_PATCH 0
#endif
#endif

// Console
void CON_Shutdown( void );
void CON_Init( void );
char *CON_Input( void );
void CON_Print( const char *message );

unsigned int CON_LogSize( void );
unsigned int CON_LogWrite( const char *in );
unsigned int CON_LogRead( char *out, unsigned int outSize );

#ifdef __APPLE__
char *Sys_StripAppBundle( char *pwd );
#endif

void Sys_GLimpSafeInit( void );
void Sys_GLimpInit( void );
void Sys_PlatformInit( void );
void Sys_PlatformExit( void );
void Sys_SigHandler( int signal ) __attribute__ ((noreturn));
void Sys_ErrorDialog( const char *error );
void Sys_AnsiColorPrint( const char *msg );

int Sys_PID( void );
qboolean Sys_PIDIsRunning( int pid );
