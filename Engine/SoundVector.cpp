#include "SoundVector.h"
#include "Sound.h"

#if COMPLETE

ChannelVector Vector_CreateEmpty()
{
	ChannelVector cv;
	cv.ppData = NULL;
	cv.size = 0;
	cv.reserve = 0;
	return cv;
}

ChannelVector Vector_CreateReserve( int Count )
{
	ChannelVector cv;
	cv.ppData = ( struct Channel** )malloc( sizeof( struct Channel* ) * Count );
	cv.size = 0;
	cv.reserve = Count;
	return cv;
}

ChannelVector Vector_CreateInitialized( int Count, Channel ** ppChannels )
{
	ChannelVector cv = Vector_CreateReserve( Count );
	for( int i = 0; i < cv.size; ++i )
	{
		cv.ppData[ i ] = ppChannels[ i ];
		cv.size += 1;
	}

	return cv;
}

bool Vector_IsEmpty( ChannelVector * pVec )
{
	return pVec->size == 0;
}

void Vector_PushBack( ChannelVector * pVec, Channel * pChannel )
{
	if( pVec->size < pVec->reserve )
	{
		pVec->ppData[ pVec->size ] = pChannel;
		pVec->size += 1;
	}
	else
	{
		ChannelVector temp = Vector_CreateInitialized( pVec->size >> 1, pVec->ppData );
		if( !Vector_IsEmpty( pVec ) )
		{
			free( pVec->ppData );
		}
		pVec->ppData = temp.ppData;
		pVec->reserve = temp.reserve;
		pVec->size = temp.size;
	}
}

void Vector_PopBack( ChannelVector * pVec )
{
	if( Vector_IsEmpty( pVec ) )
		return;
	
	pVec->size -= 1;
	pVec->ppData[ pVec->size ] = NULL;
}

struct Channel * Vector_GetIndexed( ChannelVector * pVec, int i )
{
	return pVec->ppData[ i ];
}

unsigned Vector_GetSize( ChannelVector * pVec )
{
	return pVec->size;
}

void Vector_Clear( ChannelVector * pVec )
{
	const unsigned size = Vector_GetSize( pVec );
	if( size > 0 )
	{
		for( int i = 0; i < size; i += 1 )
		{
			pVec->ppData[ i ] = NULL;
		}

		pVec->size = 0;

	}
}

struct Channel *Vector_GetFront( ChannelVector *pVec )
{
	return pVec->ppData[ 0 ];
}

struct Channel *Vector_GetBack( ChannelVector * pVec )
{
	return pVec->ppData[ pVec->size - 1 ];
}

void Vector_Erase( ChannelVector * pVec, int Idx )
{
	const unsigned size = Vector_GetSize( pVec );
	if( Idx < size )
	{
		for( int i = Idx; i < size; i += 1 )
		{
			pVec->ppData[ i ] = pVec->ppData[ i + 1 ];
		}

		Vector_PopBack( pVec );
	}
}

void Vector_EraseRange( ChannelVector * pVec, int StartIdx, int EndIdx )
{
	const int size = Vector_GetSize( pVec );
	if( EndIdx == size )
	{
		for( int i = StartIdx; i < EndIdx; i += 1 )
		{
			Vector_PopBack( pVec );
		}
	}
	else
	{
		for( int i = StartIdx; i < EndIdx; i += 1 )
		{
			Vector_Erase( pVec, i );
		}
	}
}

int Vector_FindElement( ChannelVector * pVec, Channel * pChan )
{
	const int size = Vector_GetSize( pVec );
	int count = -1;
	for( int i = 0; i < size; i += 1 )
	{
		if( pVec->ppData[ i ] == pChan )
		{
			count = i;
			break;
		}
	}

	return count;
}
#endif