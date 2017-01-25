#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Vec2.h"

typedef struct _Dude
{
	Vec2 pos;
}Dude;

Dude  Dude_Create( float X, float Y );
void  Dude_ClampToScreen( Dude *pDude );
void  Dude_Draw( Dude *pDude, Graphics* gfx );
void  Dude_UpdateKeyboard( Dude *pDude, const Keyboard* pKbd, float dt );
void  Dude_UpdateMouse( Dude *pDude, const Mouse* mouse, float dt );
Vec2  Dude_GetPos( Dude *pDude );
float Dude_GetWidth( Dude *pDude );
float Dude_GetHeight( Dude *pDude );
