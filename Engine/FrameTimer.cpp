#include "FrameTimer.h"


FrameTimer Timer_Create()
{
	FrameTimer t = { 0 };
	LARGE_INTEGER li = { 0 };

	// Check the frequency and pre divide result, so we can 
	// use multiplication for each frame instead
	QueryPerformanceFrequency( &li );
	t.recipFreq = 1.0 / ( double )li.QuadPart;

	// Initialize the timer vars
	QueryPerformanceCounter( &li );
	t.start = li.QuadPart;
	t.stop = t.start;

	return t;
}

float Timer_Mark(FrameTimer *pTimer)
{
	QueryPerformanceCounter( &pTimer->stop );
	long long diff = pTimer->stop - pTimer->start;
	pTimer->start = pTimer->stop;

	// TODO: Check on return value
	const float frameTime = ( float )( ( double )diff * pTimer->recipFreq );
	return frameTime;
}
