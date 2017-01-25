#include "Dude.h"
#include "Graphics.h"


const float Dude_speed = 1.0f * 60.0f;
const float Dude_width = 20.0f;
const float Dude_height = 20.0f;

Dude Dude_Create( float X, float Y )
{
	Dude d;
	d.pos.x = X;
	d.pos.y = Y;
}

void Dude_ClampToScreen( Dude * pDude )
{
	const float right = pDude->pos.x + Dude_width;
	if( pDude->pos.x < 0 )
	{
		pDude->pos.x = 0;
	}
	else if( right >= ( float )Gfx_ScreenWidth )
	{
		pDude->pos.x = ( float)( Gfx_ScreenWidth - 1 ) - Dude_width;
	}

	const float bottom = pDude->pos.y + Dude_height;
	if( pDude->pos.y < 0 )
	{
		pDude->pos.y = 0;
	}
	else if( bottom >= ( float )( Gfx_ScreenHeight ) )
	{
		pDude->pos.y = ( float )( Gfx_ScreenHeight - 1 ) - Dude_height;
	}
}

void Dude_Draw( Dude * pDude, Graphics * gfx )
{
	const int x_int = ( int )( pDude->pos.x );
	const int y_int = ( int )( pDude->pos.y );

	Gfx_PutPixelRGB(gfx, 7 + x_int,0 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,0 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,0 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,0 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,0 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,0 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,1 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,1 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,1 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,1 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,1 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,1 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,1 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,1 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,1 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,1 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,2 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,2 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,2 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,2 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,2 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,3 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,3 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,3 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,4 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,4 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,4 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,5 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,5 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,6 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,6 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,6 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,6 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,6 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,6 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,6 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,6 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,6 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,6 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,7 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,7 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,7 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,7 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,7 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,7 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,8 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,8 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,8 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,8 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,8 + y_int,255,255,255 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,8 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,8 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,8 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,9 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,9 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,10 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,10 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,10 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,11 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,11 + y_int,20,14,18 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,11 + y_int,18,11,14 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,11 + y_int,18,12,14 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,11 + y_int,18,12,14 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,11 + y_int,21,13,16 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,11 + y_int,24,11,15 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,11 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,11 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,11 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,12 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,12 + y_int,23,9,23 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,12 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,12 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,12 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,12 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,13 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,13 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,13 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,13 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,13 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,13 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,13 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,13 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,13 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,13 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,14 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,14 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,14 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,14 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,14 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,14 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,14 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,14 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,14 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,14 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,14 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,14 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,14 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,14 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,14 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,14 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,14 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,14 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,15 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,15 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,15 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,15 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,15 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,15 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,15 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,15 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,15 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,15 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,15 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,15 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,15 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,15 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,15 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,15 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,16 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,16 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,16 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,16 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,16 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,16 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,16 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,16 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,16 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,16 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,16 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,16 + y_int,251,192,224 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,16 + y_int,135,26,68 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,16 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,16 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,16 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,17 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,18 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,18 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,18 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,18 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,18 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,18 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,18 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,18 + y_int,254,221,88 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,18 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,18 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,19 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,19 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,19 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,19 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,19 + y_int,0,0,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,19 + y_int,0,0,0 );
}

void Dude_UpdateKeyboard( Dude *pDude, const Keyboard* kbd, float dt )
{
	Vec2 vel = Vec_Create( 0.0f,0.0f );
	if( Kbd_KeyIsPressed( kbd, VK_RIGHT ) )
	{
		vel.x += 1.0f;
	}
	if( Kbd_KeyIsPressed( kbd, VK_LEFT ) )
	{
		vel.x -= 1.0f;
	}
	if( Kbd_KeyIsPressed( kbd, VK_DOWN ) )
	{
		vel.y += 1.0f;
	}
	if( Kbd_KeyIsPressed( kbd, VK_UP ) )
	{
		vel.y -= 1.0f;
	}

	Vec_Normalize( &vel );
	Vec_Scale( &vel, Dude_speed );
	Vec_Scale( &vel, dt );
	Vec_Accumulate( &pDude->pos, &vel );

}

void Dude_UpdateMouse( Dude * pDude, const Mouse * mouse, float dt )
{
	if( Mouse_LeftIsPressed(mouse) )
	{
		Vec2 size = Vec_Create( ( float )Dude_width, Dude_height );
		Vec_Scale( &size, .5f );

		const Vec2 center = Vec_Add( &pDude->pos, &size );
		const Vec2 mouse_pos = Vec_Create( ( float )Mouse_GetPosX( mouse ), ( float )Mouse_GetPosY( mouse ) );
		const Vec2 toPointer = Vec_Subtract( &mouse_pos, &center );

		// dead zone radius = sqrt( 2 )
		if( Vec_GetLengthSq(&toPointer) > 2.0f )
		{
			Vec2 delta = Vec_GetNormalized( &toPointer );
			Vec_Scale( &delta, Dude_speed * dt );
			Vec_Accumulate( &pDude->pos, &delta );
		}
	}
}

Vec2 Dude_GetPos( Dude * pDude )
{
	return pDude->pos;
}

float Dude_GetWidth( Dude * pDude )
{
	return Dude_width;
}

float Dude_GetHeight( Dude * pDude )
{
	return Dude_height;
}
