#include "Mouse.h"
#include <string.h>

const unsigned int Mouse_bufferSize = 4u;
MouseEvent MouseEvent_Create()
{
	MouseEvent e;
	e.type = MouseInvalid;
	e.leftIsPressed = false;
	e.rightIsPressed = false;
	e.x = 0;
	e.y = 0;
	return e;
}

MouseEvent MouseEvent_CreateInitialized( MouseType type, const Mouse * pParent )
{
	MouseEvent e;
	e.type = type;
	e.leftIsPressed = pParent->leftIsPressed;
	e.rightIsPressed = pParent->rightIsPressed;
	e.x = pParent->x;
	e.y = pParent->y;

	return e;
}

_Bool MouseEvent_IsValid( MouseEvent * pEvent )
{
	return pEvent->type != MouseInvalid;
}

MouseType MouseEvent_GetType( MouseEvent * pEvent )
{
	return pEvent->type;
}

Coord MouseEvent_GetPos( MouseEvent * pEvent )
{
	Coord c;
	c.x = pEvent->x;
	c.y = pEvent->y;
	return c;
}

int MouseEvent_GetPosX( MouseEvent * pEvent )
{
	return pEvent->x;
}

int MouseEvent_GetPosY( MouseEvent * pEvent )
{
	return pEvent->y;
}

_Bool MouseEvent_LeftIsPressed( MouseEvent * pEvent )
{
	return pEvent->leftIsPressed;
}

_Bool MouseEvent_RightIsPressed( MouseEvent * pEvent )
{
	return pEvent->rightIsPressed;
}

Mouse Mouse_Create()
{
	Mouse m = { 0 };
	m.isInWindow = Mouse_IsInWindow( &m );
	
	return m;
}

Coord Mouse_GetPos( Mouse * pMouse )
{
	Coord c;
	c.x = pMouse->x;
	c.y = pMouse->y;
	return c;
}

int Mouse_GetPosX( Mouse * pMouse )
{
	return pMouse->x;
}

int Mouse_GetPosY( Mouse * pMouse )
{
	return pMouse->y;
}

bool Mouse_LeftIsPressed( Mouse * pMouse )
{
	return pMouse->leftIsPressed;
}

bool Mouse_RightIsPressed( Mouse * pMouse )
{
	return pMouse->rightIsPressed;
}

bool Mouse_IsInWindow( Mouse * pMouse )
{
	return pMouse->isInWindow;
}

MouseEvent Mouse_Read( Mouse * pMouse )
{	
	if( !Mouse_IsEmpty( pMouse ) )
	{
		MouseEvent e = pMouse->buffer[ 0 ];

		for( int i = 0; i < pMouse->elementsInBuffer - 1; i += 1 )
		{
			pMouse->buffer[ i ] = pMouse->buffer[ i + 1 ];
		}

		pMouse->elementsInBuffer -= 1;
		return e;
	}

	return MouseEvent_Create();
}

bool Mouse_IsEmpty( Mouse * pMouse )
{
	return pMouse->elementsInBuffer == 0;
}

void Mouse_Flush( Mouse * pMouse )
{
	pMouse->elementsInBuffer = 0;
}

void Mouse_OnMouseMove( Mouse * pMouse, int newx, int newy )
{
	pMouse->x = newx;
	pMouse->y = newy;

	pMouse->buffer[ pMouse->elementsInBuffer ] = MouseEvent_CreateInitialized( Move, pMouse );
	Mouse_TrimBuffer(pMouse);
}

void Mouse_OnMouseLeave( Mouse * pMouse )
{
	pMouse->isInWindow = false;
}

void Mouse_OnMouseEnter( Mouse * pMouse )
{
	pMouse->isInWindow = true;
}

void Mouse_OnLeftPressed( Mouse * pMouse, int x, int y )
{
	pMouse->rightIsPressed = true;

	pMouse->buffer[ pMouse->elementsInBuffer ] =
		MouseEvent_CreateInitialized( LPress, pMouse );
	pMouse->elementsInBuffer += 1;
	Mouse_TrimBuffer( pMouse );
}

void Mouse_OnLeftReleased( Mouse * pMouse, int x, int y )
{
	pMouse->leftIsPressed = false;

	pMouse->buffer[ pMouse->elementsInBuffer ] =
		MouseEvent_CreateInitialized( LRelease, pMouse );
	pMouse->elementsInBuffer += 1;
	Mouse_TrimBuffer( pMouse );
}

void Mouse_OnRightPressed( Mouse * pMouse, int x, int y )
{
	pMouse->rightIsPressed = true;

	pMouse->buffer[ pMouse->elementsInBuffer ] =
		MouseEvent_CreateInitialized( RPress, pMouse );
	pMouse->elementsInBuffer += 1;
	Mouse_TrimBuffer( pMouse );
}

void Mouse_OnRightReleased( Mouse * pMouse, int x, int y )
{
	pMouse->rightIsPressed = false;

	pMouse->buffer[ pMouse->elementsInBuffer ] =
		MouseEvent_CreateInitialized( RRelease, pMouse );
	pMouse->elementsInBuffer += 1;
	Mouse_TrimBuffer( pMouse );
}

void Mouse_OnWheelUp( Mouse * pMouse, int x, int y )
{
	pMouse->buffer[ pMouse->elementsInBuffer ] = 
		MouseEvent_CreateInitialized( WheelUp, pMouse );
	pMouse->elementsInBuffer += 1;
	Mouse_TrimBuffer( pMouse );
}

void Mouse_OnWheelDown( Mouse * pMouse, int x, int y )
{
	pMouse->buffer[ pMouse->elementsInBuffer ] = 
		MouseEvent_CreateInitialized( WheelDown, pMouse );
	pMouse->elementsInBuffer += 1;
	Mouse_TrimBuffer( pMouse );
}

void Mouse_TrimBuffer( Mouse * pMouse )
{
	if( pMouse->elementsInBuffer >= 4 )
	{
		for( int i = 1; i < 4; ++i )
		{
			pMouse->buffer[ i - 1 ] = pMouse->buffer[ i ];
		}

		pMouse->elementsInBuffer -= 1;
	}
}
