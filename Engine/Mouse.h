#pragma once
#include <stdbool.h>

typedef struct _Coord
{
	int x, y;
}Coord;

typedef enum _MouseType
{
	MouseInvalid,
	LPress,
	LRelease,
	RPress,
	RRelease,
	WheelUp,
	WheelDown,
	Move
}MouseType;

typedef struct _MouseEvent
{
	MouseType type;
	_Bool leftIsPressed;
	_Bool rightIsPressed;
	int x;
	int y;
}MouseEvent;

MouseEvent MouseEvent_Create();
MouseEvent MouseEvent_CreateInitialized( MouseType type, const struct Mouse* pParent );
_Bool MouseEvent_IsValid( MouseEvent *pEvent );
MouseType MouseEvent_GetType( MouseEvent *pEvent );
Coord MouseEvent_GetPos( MouseEvent *pEvent );
int MouseEvent_GetPosX( MouseEvent *pEvent );
int MouseEvent_GetPosY( MouseEvent *pEvent );
_Bool MouseEvent_LeftIsPressed( MouseEvent *pEvent );
_Bool MouseEvent_RightIsPressed( MouseEvent *pEvent );


extern const unsigned int Mouse_bufferSize;

typedef struct _Mouse
{
	int x;
	int y;
	_Bool leftIsPressed;
	_Bool rightIsPressed;
	_Bool isInWindow;
	MouseEvent buffer[ 4 ];
	int elementsInBuffer;
}Mouse;

Mouse Mouse_Create();
Coord Mouse_GetPos( Mouse *pMouse );
int Mouse_GetPosX( Mouse *pMouse );
int Mouse_GetPosY( Mouse *pMouse );
bool Mouse_LeftIsPressed( Mouse *pMouse );
bool Mouse_RightIsPressed( Mouse *pMouse );
bool Mouse_IsInWindow( Mouse *pMouse );
MouseEvent Mouse_Read( Mouse *pMouse );
bool Mouse_IsEmpty( Mouse *pMouse );
void Mouse_Flush( Mouse *pMouse );

//private:
void Mouse_OnMouseMove( Mouse *pMouse, int x, int y );
void Mouse_OnMouseLeave( Mouse *pMouse );
void Mouse_OnMouseEnter( Mouse *pMouse );
void Mouse_OnLeftPressed( Mouse *pMouse, int x, int y );
void Mouse_OnLeftReleased( Mouse *pMouse, int x, int y );
void Mouse_OnRightPressed( Mouse *pMouse, int x, int y );
void Mouse_OnRightReleased( Mouse *pMouse, int x, int y );
void Mouse_OnWheelUp( Mouse *pMouse, int x, int y );
void Mouse_OnWheelDown( Mouse *pMouse, int x, int y );
void Mouse_TrimBuffer( Mouse *pMouse );
