#include "FrameTimer.h"

// TODO: Use Windows performance timer instead of time()
FrameTimer Timer_Create()
{
	FrameTimer t = { 0 };
	
	time( &t.last );
	return t;
}

float Timer_Mark(FrameTimer *pTimer)
{
	const unsigned old = pTimer->last;
	time( &pTimer->last );
	const float frameTime = ( float )( pTimer->last - old ) * .001f;

	// TODO: Check on return value
	return frameTime;
}
