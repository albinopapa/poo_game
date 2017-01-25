#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

extern const float Goal_dimension;


typedef struct _Goal
{	
	bool colorIncreasing;
	Vec2 pos;
	MyColor color;
}Goal;

Goal Goal_Create( const Vec2* pos_in );
void Goal_Draw( Goal *pGoal, Graphics* gfx );
bool Goal_TestCollision( Goal *pGoal, const Dude* dude );
void Goal_Respawn( Goal *pGoal, const Vec2* pos_in );
void Goal_UpdateColor( Goal *pGoal );
