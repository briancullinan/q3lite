/*

*/

// snddma_null.c
// all other sound mixing is portable

#include "../qcommon/q_shared.h"
#include "../qcommon/qcommon.h"

qboolean SNDDMA_Init(void)
{
	return qfalse;
}

int	SNDDMA_GetDMAPos(void)
{
	return 0;
}

void SNDDMA_Shutdown(void)
{
}

void SNDDMA_BeginPainting (void)
{
}

void SNDDMA_Submit(void)
{
}

#ifdef USE_VOIP
void SNDDMA_StartCapture(void)
{
}

int SNDDMA_AvailableCaptureSamples(void)
{
	return 0;
}

void SNDDMA_Capture(int samples, byte *data)
{
}

void SNDDMA_StopCapture(void)
{
}

void SNDDMA_MasterGain( float val )
{
}
#endif


sfxHandle_t S_RegisterSound( const char *name, qboolean compressed ) 
{
	return 0;
}

void S_StartLocalSound( sfxHandle_t sfxHandle, int channelNum ) {
}

void S_ClearSoundBuffer( void ) {
}
