#pragma once

typedef struct _Vec2
{
	float x;
	float y;
}Vec2;

Vec2 Vec_Create( float x_in, float y_in );
Vec2 Vec_Add( const Vec2* plhs, const Vec2* prhs );
Vec2* Vec_Accumulate( Vec2* plhs, const Vec2* rhs );
Vec2 Vec_Multiply( const Vec2* plhs, float rhs );
Vec2* Vec_Scale( Vec2* plhs, float rhs );
Vec2 Vec_Subtract( const Vec2* plhs, const Vec2* prhs );
Vec2* Vec_SubtractAssign( Vec2* plhs, const Vec2* rhs );
float Vec_GetLength( const Vec2* plhs );
float Vec_GetLengthSq( const Vec2* plhs );
Vec2* Vec_Normalize( Vec2* plhs );
Vec2 Vec_GetNormalized( const Vec2* plhs );
