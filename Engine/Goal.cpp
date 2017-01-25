#include "Goal.h"

const float Goal_dimension = 20;


Goal Goal_Create( const Vec2 * pos_in )
{
	Goal g;
	g.colorIncreasing = true;
	g.pos = *pos_in;
	g.color = Color_CreateRGB( 127, 0, 0 );
	return g;
}

void Goal_Draw( Goal * pGoal, Graphics * gfx )
{
	Gfx_DrawRectDim(
		gfx,
		( int )pGoal->pos.x,
		( int )pGoal->pos.y,
		( int )Goal_dimension,
		( int )Goal_dimension,
		pGoal->color );
}

bool Goal_TestCollision( Goal * pGoal, const Dude * dude )
{
	const float duderight = Dude_GetPos( dude ).x + Dude_GetWidth( dude );
	const float dudebottom = Dude_GetPos( dude ).y + Dude_GetHeight( dude );
	const float pooright = pGoal->pos.x + Goal_dimension;
	const float poobottom = pGoal->pos.y + Goal_dimension;

	return
		duderight >= pGoal->pos.x &&
		Dude_GetPos( dude ).x <= pooright &&
		dudebottom >= pGoal->pos.y &&
		Dude_GetPos( dude ).y <= poobottom;
}

void Goal_Respawn( Goal * pGoal, const Vec2 * pos_in )
{
	pGoal->pos = *pos_in;
}

void Goal_UpdateColor( Goal * pGoal )
{
	if( pGoal->colorIncreasing )
	{
		if( Color_GetR( pGoal->color ) >= 253 )
		{
			pGoal->colorIncreasing = false;
		}
		else
		{
			pGoal->color = Color_CreateRGB(
				Color_GetR( pGoal->color ) + 2,
				Color_GetG( pGoal->color ) + 4,
				Color_GetB( pGoal->color ) + 4 );
		}
	}
	else
	{
		if( Color_GetR( pGoal->color ) <= 127 )
		{
			pGoal->colorIncreasing = true;
		}
		else
		{
			pGoal->color = Color_CreateRGB(
				Color_GetR( pGoal->color ) - 2,
				Color_GetG( pGoal->color ) - 4,
				Color_GetB( pGoal->color ) - 4 );
		}
	}
}