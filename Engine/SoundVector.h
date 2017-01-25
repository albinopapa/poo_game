#pragma once
#include <stdbool.h>

#if defined(COMPLETE) && (COMPLETE == 1)
typedef struct _ChannelVector
{
	struct Channel **ppData;
	unsigned size, reserve;
}ChannelVector;

ChannelVector Vector_CreateEmpty();
ChannelVector Vector_CreateReserve( int Count );
ChannelVector Vector_CreateInitialized( int Count, struct Channel **ppChannels );
bool Vector_IsEmpty( ChannelVector *pVec );
void Vector_PushBack( ChannelVector *pVec, struct Channel*pChannel );
void Vector_PopBack( ChannelVector *pVec );
struct Channel *Vector_GetIndexed( ChannelVector *pVec, int i );
unsigned Vector_GetSize( ChannelVector *pVec );
void Vector_Clear( ChannelVector *pVec );
struct Channel *Vector_GetFront( ChannelVector *pVec );
struct Channel *Vector_GetBack( ChannelVector *pVec );
void Vector_Erase( ChannelVector *pVec, int Idx );
void Vector_EraseRange( ChannelVector *pVec, int StartIdx, int EndIdx );
int Vector_FindElement( ChannelVector *pVec, struct Channel *pChan );
#endif
