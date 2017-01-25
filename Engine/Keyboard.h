#pragma once

#include <stdbool.h>

typedef enum _EventType
{
	Press,
	Release,
	Invalid
}KeyEventType;

typedef struct _Event
{
	KeyEventType type;
	unsigned char code;
}KbdEvent;

KbdEvent KbdEvent_Create( KeyEventType Type, unsigned char Code );
bool KbdEvent_IsPress( KbdEvent *pEvent );
bool KbdEvent_IsRelease( KbdEvent *pEvent );
bool KbdEvent_IsValid( KbdEvent *pEvent );
unsigned char KbdEvent_GetCode( KbdEvent *pEvent );

extern const unsigned int Kbd_nKeys;
extern const unsigned int Kbd_bufferSize;

typedef struct _KeyEventQueue
{
	KbdEvent keyevents[ 4u ];
	KbdEvent *head, *tail;
}KeyEventQueue;

typedef struct _CharQueue
{
	char charbuffer[ 4u ];
	char *head, *tail;
}CharQueue;

typedef struct _Keyboard
{
	_Bool autorepeatEnabled;
	int keystates[ 256u ];
	KeyEventQueue keyqueue;
	CharQueue charqueue;
}Keyboard;

Keyboard	Kbd_Create();
bool		Kbd_KeyIsPressed( Keyboard *pKbd, unsigned char keycode );
KbdEvent	Kbd_ReadKey( Keyboard *pKbd );
bool		Kbd_KeyIsEmpty( Keyboard *pKbd );
char		Kbd_ReadChar( Keyboard *pKbd );
bool		Kbd_CharIsEmpty( Keyboard *pKbd );
void		Kbd_FlushKey( Keyboard *pKbd );
void		Kbd_FlushChar( Keyboard *pKbd );
void		Kbd_Flush( Keyboard *pKbd );
void		Kbd_EnableAutorepeat( Keyboard *pKbd );
void		Kbd_DisableAutorepeat( Keyboard *pKbd );
bool		Kbd_AutorepeatIsEnabled( Keyboard *pKbd );
void		Kbd_OnKeyPressed( Keyboard *pKbd, unsigned char keycode );
void		Kbd_OnKeyReleased( Keyboard *pKbd, unsigned char keycode );
void		Kbd_OnChar( Keyboard *pKbd, char character );
