#include "Vec2.h"
#include <math.h>

Vec2 Vec_Create( float x_in,float y_in )
{
	Vec2 v;
	v.x = x_in;
	v.y = y_in;

	return v;
}

Vec2 Vec_Add( const Vec2* plhs, const Vec2* prhs )
{
	Vec2 v;
	v.x = plhs->x + prhs->x;
	v.y = plhs->y + prhs->y;
	return v;
}

Vec2* Vec_Accumulate( Vec2* plhs, const Vec2* rhs )
{
	plhs->x += rhs->x;
	plhs->y += rhs->y;
	return plhs;
}

Vec2 Vec_Multiply( const Vec2* plhs, float rhs )
{
	Vec2 v;
	v.x = plhs->x * rhs;
	v.y = plhs->y * rhs;
	return v;
}

Vec2* Vec_Scale( Vec2* plhs, float rhs )
{
	plhs->x *= rhs;
	plhs->y *= rhs;
	return plhs;
}

Vec2 Vec_Subtract( const Vec2* plhs, const Vec2* prhs )
{
	Vec2 v;
	v.x = plhs->x - prhs->x;
	v.y = plhs->y - prhs->y;
	return v;
}

Vec2* Vec_SubtractAssign( Vec2* plhs, const Vec2* rhs )
{
	plhs->x -= rhs->x;
	plhs->y -= rhs->y;
	return plhs;
}

float Vec_GetLength( const Vec2* plhs )
{
	return sqrt( Vec_GetLengthSq( plhs ) );
}

float Vec_GetLengthSq( const Vec2* plhs )
{
	return plhs->x * plhs->x + plhs->y * plhs->y;
}

Vec2* Vec_Normalize( Vec2* plhs )
{
	*plhs = Vec_GetNormalized( plhs );
	return plhs;
}

Vec2 Vec_GetNormalized( const Vec2* plhs )
{
	const float len = Vec_GetLength( plhs );
	if( len != 0.0f )
	{
		return Vec_Multiply( plhs, ( 1.f / len ) );
	}
	return *plhs;
}
