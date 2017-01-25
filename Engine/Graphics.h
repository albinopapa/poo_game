#pragma once

#include <d3d11.h>
#include <stdbool.h>
//#include "ChiliException.h"
#include "Colors.h"


extern const int Gfx_ScreenWidth;
extern const int Gfx_ScreenHeight;

// vertex format for the framebuffer fullscreen textured quad
typedef struct _FSQVertex
{
	float x, y, z;		// position
	float u, v;			// texcoords
}FSQVertex;

typedef struct _Graphics
{
	ID3D11Device				*pDevice;
	ID3D11DeviceContext			*pImmediateContext;
	IDXGISwapChain				*pSwapChain;
	ID3D11RenderTargetView		*pRenderTargetView;
	ID3D11Texture2D				*pSysBufferTexture;
	ID3D11ShaderResourceView	*pSysBufferTextureView;
	ID3D11PixelShader			*pPixelShader;
	ID3D11VertexShader			*pVertexShader;
	ID3D11Buffer				*pVertexBuffer;
	ID3D11InputLayout			*pInputLayout;
	ID3D11SamplerState			*pSamplerState;
	D3D11_MAPPED_SUBRESOURCE	mappedSysBufferTexture;
	MyColor *                      pSysBuffer;
}Graphics;

HRESULT Gfx_Create( struct HWNDKey* key, Graphics *Gfx );
HRESULT Gfx_EndFrame( Graphics *pGfx);
void Gfx_BeginFrame( Graphics *pGfx );
void Gfx_PutPixelRGB( Graphics *pGfx, int x, int y, int r, int g, int b );
void Gfx_PutPixelColor( Graphics *pGfx, int x, int y, MyColor  c );
void Gfx_DrawRect( Graphics *pGfx, int x0, int y0, int x1, int y1, MyColor  c );
void Gfx_DrawRectDim( Graphics *pGfx, int x0, int y0, int width, int height, MyColor  c );
void Gfx_DrawCircle( Graphics *pGfx, int x, int y, int radius, MyColor  c );
void Gfx_Destroy( Graphics *pGfx );
