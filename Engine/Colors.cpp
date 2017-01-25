#include "Colors.h"

const MyColor Colors_White = { MakeRGB( 255u, 255u, 255u ) };
const MyColor Colors_Black = { MakeRGB( 0u, 0u, 0u ) };
const MyColor Colors_Gray = { MakeRGB( 0x80u, 0x80u, 0x80u ) };
const MyColor Colors_LightGray = { MakeRGB( 0xD3u, 0xD3u, 0xD3u ) };
const MyColor Colors_Red = { MakeRGB( 255u, 0u, 0u ) };
const MyColor Colors_Green = { MakeRGB( 0u, 255u, 0u ) };
const MyColor Colors_Blue = { MakeRGB( 0u, 0u, 255u ) };
const MyColor Colors_Yellow = { MakeRGB( 255u, 255u, 0u ) };
const MyColor Colors_Cyan = { MakeRGB( 0u, 255u, 255u ) };
const MyColor Colors_Magenta = { MakeRGB( 255u, 0u, 255u ) };


MyColor  Color_CreateRGB( unsigned char r, unsigned char g, unsigned char b )
{
	MyColor  c;
	c.dword = ( r << 16 ) | ( g << 8 ) | b;
	return c;
}

MyColor  Color_CreateFromInt( unsigned int dw )
{
	MyColor  c;
	c.dword = dw;
	return c;
}

MyColor  Color_CreateARGB( unsigned char x, unsigned char r, unsigned char g, unsigned char b )
{
	MyColor  c;
	c.dword = ( ( x << 24u ) | ( r << 16u ) | ( g << 8u ) | b );
	return c;
}

MyColor  Color_CreateRGB_A( MyColor  col, unsigned char x )
{
	return Color_CreateFromInt( ( x << 24u ) | col.dword );
}

MyColor  * Color_Copy( MyColor * pDst, const MyColor  Src )
{
	pDst->dword = Src.dword;
	return pDst;
}

unsigned char Color_GetX( MyColor  C )
{
	return C.dword >> 24u;
}

unsigned char Color_GetA( MyColor  C )
{
	return Color_GetX( C );
}

unsigned char Color_GetR( MyColor  C )
{
	return ( C.dword >> 16u ) & 0xFFu;
}

unsigned char Color_GetG( MyColor  C )
{
	return ( C.dword >> 8u ) & 0xFFu;
}

unsigned char Color_GetB( MyColor  C )
{
	return C.dword & 0xFFu;
}

void Color_SetX( MyColor  * C, unsigned char x )
{
	C->dword = ( C->dword & 0xFFFFFFu ) | ( x << 24u );
}

void Color_SetA( MyColor  * C, unsigned char a )
{
	Color_SetX( C, a );
}

void Color_SetR( MyColor  * C, unsigned char r )
{
	C->dword = ( C->dword & 0xFF00FFFFu ) | ( r << 16u );
}

void Color_SetG( MyColor  * C, unsigned char g )
{
	C->dword = ( C->dword & 0xFFFF00FFu ) | ( g << 8u );
}

void Color_SetB( MyColor  * C, unsigned char b )
{
	C->dword = ( C->dword & 0xFFFFFF00u ) | b;
}
