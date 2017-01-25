#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

extern const float Poo_width ;
extern const float Poo_height;

typedef struct _Poo
{
	Vec2 pos;
	Vec2 vel;
	bool initialized;
}Poo;

Poo Poo_Create( Vec2 const *const pos_in, Vec2 const *const vel_in );
void Poo_Update( Poo *pPoo, float dt );
bool Poo_TestCollision( Poo *pPoo, const Dude*const dude );
void Poo_Draw( Poo *pPoo, Graphics*const gfx );
