#pragma once

#include "Graphics.h"


extern const MyColor Meter_color;
extern const int Meter_girth;
extern const int Meter_scale;

typedef struct _Meter
{	
	int level;
	int x;
	int y;
}Meter;

Meter Meter_Create( int x, int y );
void Meter_IncreaseLevel( Meter *pMeter );
int Meter_GetLevel( Meter *pMeter );
void Meter_Draw( Meter *pMeter, Graphics* gfx );
