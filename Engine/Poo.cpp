#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

const float Poo_width = 24.f;
const float Poo_height = 24.f;

Poo Poo_Create( Vec2 const *const pos_in, Vec2 const *const vel_in )
{
	Poo p;
	p.initialized = true;
	p.pos = *pos_in;
	p.vel = *vel_in;

	return p;
}

void Poo_Update( Poo *pPoo, float dt )
{
	assert( pPoo->initialized == true );
	const Vec2 delta = Vec_Multiply( &pPoo->vel, dt );
	Vec_Accumulate( &pPoo->pos, &delta );

	const float right = pPoo->pos.x + Poo_width;
	if( pPoo->pos.x < 0.f )
	{
		pPoo->pos.x = 0.f;
		pPoo->vel.x = -pPoo->vel.x;
	}
	else if( right >= (float)( Gfx_ScreenWidth ) )
	{
		pPoo->pos.x = (float)( Gfx_ScreenWidth - 1 ) - Poo_width;
		pPoo->vel.x = -pPoo->vel.x;
	}

	const float bottom = pPoo->pos.y + Poo_height;
	if( pPoo->pos.y < 0.f )
	{
		pPoo->pos.y = 0.f;
		pPoo->vel.y = -pPoo->vel.y;
	}
	else if( bottom >= (float)( Gfx_ScreenHeight ) )
	{
		pPoo->pos.y = (float)( Gfx_ScreenHeight - 1 ) - Poo_height;
		pPoo->vel.y = -pPoo->vel.y;
	}
}

bool Poo_TestCollision( Poo *pPoo, const Dude*const dude )
{
	assert( pPoo->initialized == true );
	const float duderight =  Dude_GetPos(dude).x + Dude_GetWidth(dude);
	const float dudebottom = Dude_GetPos(dude).y + Dude_GetHeight(dude);
	const float pooright =  pPoo->pos.x + Poo_width;
	const float poobottom = pPoo->pos.y + Poo_height;

	return
		duderight >= pPoo->pos.x &&
		Dude_GetPos( dude ).x <= pooright &&
		dudebottom >= pPoo->pos.y &&
		Dude_GetPos( dude ).y <= poobottom;
}

void Poo_Draw( Poo *pPoo, Graphics*const gfx )
{
	assert( pPoo->initialized == true );

	const int x_int = (int)( pPoo->pos.x );
	const int y_int = (int)( pPoo->pos.y );

	Gfx_PutPixelRGB(gfx, 14 + x_int,0 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,1 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,1 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,1 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,2 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,2 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,2 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,3 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,4 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,4 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,4 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,5 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,5 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,5 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,6 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,6 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,7 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,7 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,7 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,7 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,8 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,8 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,8 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,9 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,9 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,9 + y_int,102,57,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,9 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,9 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,9 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,9 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,10 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,10 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,10 + y_int,102,57,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,10 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,10 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,10 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,10 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,11 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,11 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,11 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,11 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,11 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,11 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,11 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,11 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,12 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,12 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,12 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,12 + y_int,111,62,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,12 + y_int,102,57,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,12 + y_int,102,57,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,12 + y_int,102,57,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,12 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,13 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,13 + y_int,109,61,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,13 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,13 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,13 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,13 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,13 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,13 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,14 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,14 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,14 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,14 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,14 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,14 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,14 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,14 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,14 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,14 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,14 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,15 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,15 + y_int,116,65,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,15 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,15 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,15 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,15 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,16 + y_int,116,65,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,16 + y_int,109,61,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,16 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,16 + y_int,123,69,0 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,16 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,17 + y_int,87,49,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,17 + y_int,87,49,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,17 + y_int,87,49,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,17 + y_int,87,49,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,17 + y_int,43,24,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,17 + y_int,40,22,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,17 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,17 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,17 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,17 + y_int,123,69,0 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,17 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,18 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,18 + y_int,123,69,0 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 22 + x_int,18 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,19 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,19 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,19 + y_int,123,69,0 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,19 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,19 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 22 + x_int,19 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 23 + x_int,19 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,20 + y_int,123,69,0 );
	Gfx_PutPixelRGB(gfx, 19 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,20 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 22 + x_int,20 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 23 + x_int,20 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,21 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,21 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,21 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,21 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,21 + y_int,138,77,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 7 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 8 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 9 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 10 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 11 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 12 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 13 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 14 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 15 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 16 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 17 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 18 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 20 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 21 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 22 + x_int,21 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 0 + x_int,22 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,22 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,22 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,22 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,22 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,22 + y_int,65,36,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,22 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 1 + x_int,23 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 2 + x_int,23 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 3 + x_int,23 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 4 + x_int,23 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 5 + x_int,23 + y_int,51,28,0 );
	Gfx_PutPixelRGB(gfx, 6 + x_int,23 + y_int,51,28,0 );
}