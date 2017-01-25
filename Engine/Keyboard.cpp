#include "Keyboard.h"
#include <string.h>

const unsigned int Kbd_nKeys = 256u;
const unsigned int Kbd_bufferSize = 4u;
/*******************************KeyEventQueue**********************************/

KeyEventQueue EventQ_Create()
{
	KeyEventQueue q;
	memset( &q, 0x0, sizeof( KeyEventQueue ) );
	q.head = q.keyevents;
	q.tail = q.keyevents;

	return q;
}

unsigned EventQ_Size( KeyEventQueue *pQueue )
{
	return ( pQueue->tail - pQueue->head );
}

bool EventQ_IsEmpty( KeyEventQueue *pQueue )
{
	return ( pQueue->tail == pQueue->head );
}

void EventQ_Clear( KeyEventQueue *pQueue )
{
	pQueue->tail = pQueue->head;
}

void EventQ_Push( KeyEventQueue *pQueue, KbdEvent kEvent )
{
	unsigned int q_size = EventQ_Size( pQueue );
	if( q_size < 4 )
	{
		++pQueue->tail;
		( *pQueue->tail ) = kEvent;
	}
}

KbdEvent EventQ_Pop( KeyEventQueue *pQueue )
{
	if( !EventQ_IsEmpty(pQueue) )
	{
		--pQueue->tail;
		return ( *pQueue->tail );
	}

	return KbdEvent_Create( Invalid, 0 );
}

/***********************************CharQueue**********************************/
CharQueue CharQ_Create()
{
	CharQueue q;
	memset( &q, 0x0, sizeof( CharQueue ) );
	q.head = q.charbuffer;
	q.tail = q.charbuffer;
	return q;
}

unsigned CharQ_Size( CharQueue *pQueue )
{
	return ( pQueue->tail - pQueue->head );
}

bool CharQ_IsEmpty( CharQueue *pQueue )
{
	return ( pQueue->tail == pQueue->head );
}

void CharQ_Clear( CharQueue *pQueue )
{
	pQueue->tail = pQueue->head;
}

void CharQ_Push( CharQueue *pQueue, char value )
{
	unsigned int q_size = CharQ_Size( pQueue );
	if( q_size < 4 )
	{
		++pQueue->tail;
		( *pQueue->tail ) = value;
	}
}

char CharQ_Pop( CharQueue *pQueue )
{
	if( !CharQ_IsEmpty( pQueue ) )
	{
		--pQueue->tail;
		return ( *pQueue->tail );
	}

	return 0;
}
/**********************************End of queue********************************/

KbdEvent KbdEvent_Create( KeyEventType Type, unsigned char Code )
{
	KbdEvent e;
	e.code = Code;
	e.type = Type;
	return e;
}

bool KbdEvent_IsPress( KbdEvent * pEvent )
{
	return pEvent->type == Press;
}

bool KbdEvent_IsRelease( KbdEvent * pEvent )
{
	return pEvent->type == Release;
}

bool KbdEvent_IsValid( KbdEvent * pEvent )
{
	return pEvent->type != Invalid;
}

unsigned char KbdEvent_GetCode( KbdEvent * pEvent )
{
	return pEvent->code;
}

Keyboard Kbd_Create()
{
	Keyboard kbd;
	kbd.autorepeatEnabled = 0;
	kbd.charqueue = CharQ_Create();
	kbd.keyqueue = EventQ_Create();
	memset( kbd.keystates, 0x0, sizeof( int )*Kbd_nKeys );
	return kbd;
}

bool Kbd_KeyIsPressed( Keyboard * pKbd, unsigned char keycode )
{
	return pKbd->keystates[ keycode ] != false;
}

KbdEvent Kbd_ReadKey( Keyboard * pKbd )
{
	return EventQ_Pop( &pKbd->keyqueue );
}

bool Kbd_KeyIsEmpty( Keyboard * pKbd )
{
	return EventQ_IsEmpty( &pKbd->keyqueue );
}

char Kbd_ReadChar( Keyboard * pKbd )
{
	return CharQ_Pop( &pKbd->charqueue );
}

bool Kbd_CharIsEmpty( Keyboard * pKbd )
{
	return CharQ_IsEmpty( &pKbd->charqueue );
}

void Kbd_FlushKey( Keyboard * pKbd )
{
	EventQ_Clear( &pKbd->keyqueue );
}

void Kbd_FlushChar( Keyboard * pKbd )
{
	CharQ_Clear( &pKbd->charqueue );
}

void Kbd_Flush( Keyboard * pKbd )
{
	Kbd_FlushKey( pKbd );
	Kbd_FlushChar( pKbd );
}

void Kbd_EnableAutorepeat( Keyboard * pKbd )
{
	pKbd->autorepeatEnabled = true;
}

void Kbd_DisableAutorepeat( Keyboard * pKbd )
{
	pKbd->autorepeatEnabled = false;
}

bool Kbd_AutorepeatIsEnabled( Keyboard * pKbd )
{
	return pKbd->autorepeatEnabled;
}

void Kbd_OnKeyPressed( Keyboard * pKbd, unsigned char keycode )
{
	pKbd->keystates[ keycode ] = true;
	KbdEvent e;
	e.code = keycode;
	e.type = Press;
	EventQ_Push( &pKbd->keyqueue, e );
}

void Kbd_OnKeyReleased( Keyboard * pKbd, unsigned char keycode )
{
	pKbd->keystates[ keycode ] = false;
	KbdEvent e;
	e.code = keycode;
	e.type = Release;
	EventQ_Push( &pKbd->keyqueue, e );
}

void Kbd_OnChar( Keyboard * pKbd, char character )
{
	CharQ_Push( &pKbd->charqueue, character );
}
