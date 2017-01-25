#include "Meter.h"

const MyColor Meter_color = { MakeRGB( 0u, 0u, 255u ) };
const int Meter_girth = 12;
const int Meter_scale = 4;

Meter Meter_Create( int x, int y )
{
	Meter m = { 0 };
	m.x = x;
	m.y = y;

	return m;
}

void Meter_IncreaseLevel( Meter * pMeter )
{
	++pMeter->level;
}

int Meter_GetLevel( Meter * pMeter )
{
	return pMeter->level;
}

void Meter_Draw( Meter * pMeter, Graphics * gfx )
{
	Gfx_DrawRectDim(
		gfx,
		pMeter->x,
		pMeter->y,
		pMeter->level * Meter_scale,
		Meter_girth,
		Meter_color );
}