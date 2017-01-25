#pragma once
#include <time.h>


typedef struct _FrameTimer
{	
	time_t last;
}FrameTimer;

FrameTimer Timer_Create();
float Timer_Mark(FrameTimer *pTimer);