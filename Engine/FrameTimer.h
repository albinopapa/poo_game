#pragma once
#include "ChiliWin.h"


typedef struct _FrameTimer
{
	double recipFreq;
	long long start, stop;
}FrameTimer;

FrameTimer Timer_Create();
float Timer_Mark(FrameTimer *pTimer);