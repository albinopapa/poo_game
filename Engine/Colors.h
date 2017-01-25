#pragma once

typedef struct _Color
{
	unsigned int dword;
}MyColor;

// No function overloading
MyColor Color_CreateRGB( unsigned char r, unsigned char g, unsigned char b );
MyColor Color_CreateFromInt( unsigned int dw );
MyColor Color_CreateARGB( unsigned char x, unsigned char r, unsigned char g, unsigned char b );
MyColor Color_CreateRGB_A( MyColor col, unsigned char x );
MyColor *Color_Copy( MyColor* pDst, const MyColor Src );

unsigned char Color_GetX( MyColor C );
unsigned char Color_GetA( MyColor C );
unsigned char Color_GetR( MyColor C );
unsigned char Color_GetG( MyColor C );
unsigned char Color_GetB( MyColor C );
void Color_SetX( MyColor *C, unsigned char x );
void Color_SetA( MyColor *C, unsigned char a );
void Color_SetR( MyColor *C, unsigned char r );
void Color_SetG( MyColor *C, unsigned char g );
void Color_SetB( MyColor *C, unsigned char b );

#define MakeRGB(R,G,B) ((R)<<16|(G)<<8|(B))


extern const MyColor Colors_White;
extern const MyColor Colors_Black;
extern const MyColor Colors_Gray;
extern const MyColor Colors_LightGray;
extern const MyColor Colors_Red;
extern const MyColor Colors_Green;
extern const MyColor Colors_Blue;
extern const MyColor Colors_Yellow;
extern const MyColor Colors_Cyan;
extern const MyColor Colors_Magenta;
