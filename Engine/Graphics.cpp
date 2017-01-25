#include "MainWindow.h"
#include "Graphics.h"
//#include "DXErr.h"
#include <assert.h>

#include "FramebufferPS.shh"
#include "FramebufferVS.shh"

const int Gfx_ScreenWidth = 800;
const int Gfx_ScreenHeight = 600;

#define nullptr NULL

#pragma comment( lib,"d3d11.lib" )
#pragma comment(lib,"uuid.lib")

#define SafeRelease(IFace)\
{\
	if(*IFace != nullptr)\
	{\
		(*IFace)->lpVtbl->Release((*IFace));\
		(*IFace) = nullptr;\
	}\
}

HRESULT Gfx_Create( HWNDKey* key, Graphics *Gfx )
{
	assert( key->hWnd != nullptr );

	//////////////////////////////////////////////////////
	// create device and swap chain/get render target view
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory( &sd, sizeof( sd ) );
	sd.BufferCount = 1;
	sd.BufferDesc.Width =  Gfx_ScreenWidth;
	sd.BufferDesc.Height = Gfx_ScreenHeight;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 1;
	sd.BufferDesc.RefreshRate.Denominator = 60;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = key->hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	HRESULT				hr;
	UINT				createFlags = 0u;
#ifdef CHILI_USE_D3D_DEBUG_LAYER
#ifdef _DEBUG
	createFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
#endif
	
	// create device and front/back buffers
	if( FAILED( hr = D3D11CreateDeviceAndSwapChain( 
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createFlags,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&Gfx->pSwapChain,
		&Gfx->pDevice,
		nullptr,
		&Gfx->pImmediateContext ) ) )
	{
		// TODO: Create logging system
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating device and swap chain" );
	}

	// get handle to backbuffer
	ID3D11Resource* pBackBuffer;
	if( FAILED( hr = Gfx->pSwapChain->lpVtbl->GetBuffer(
		Gfx->pSwapChain,
		0,
		&IID_ID3D11Resource,
		(LPVOID*)&pBackBuffer ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Getting back buffer" );
	}

	// create a view on backbuffer that we can render to
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateRenderTargetView(
		Gfx->pDevice,
		pBackBuffer,
		nullptr,
		&Gfx->pRenderTargetView ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating render target view on backbuffer" );
	}


	// set backbuffer as the render target using created view
	Gfx->pImmediateContext->lpVtbl->OMSetRenderTargets( Gfx->pImmediateContext, 1, &Gfx->pRenderTargetView, nullptr );


	// set viewport dimensions
	D3D11_VIEWPORT vp;
	ZeroMemory( &vp, sizeof( vp ) );
	vp.Width =  ( float )( Gfx_ScreenWidth );
	vp.Height = ( float )( Gfx_ScreenHeight );
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0.0f;
	vp.TopLeftY = 0.0f;
	Gfx->pImmediateContext->lpVtbl->RSSetViewports( Gfx->pImmediateContext, 1, &vp );


	///////////////////////////////////////
	// create texture for cpu render target
	D3D11_TEXTURE2D_DESC sysTexDesc;
	ZeroMemory( &sysTexDesc, sizeof( sysTexDesc ) );
	sysTexDesc.Width  = Gfx_ScreenWidth;
	sysTexDesc.Height = Gfx_ScreenHeight;
	sysTexDesc.MipLevels = 1;
	sysTexDesc.ArraySize = 1;
	sysTexDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sysTexDesc.SampleDesc.Count = 1;
	sysTexDesc.SampleDesc.Quality = 0;
	sysTexDesc.Usage = D3D11_USAGE_DYNAMIC;
	sysTexDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	sysTexDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	sysTexDesc.MiscFlags = 0;
	// create the texture
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateTexture2D( Gfx->pDevice, &sysTexDesc, nullptr, &Gfx->pSysBufferTexture ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating sysbuffer texture" );
	}

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory( &srvDesc, sizeof( srvDesc ) );
	srvDesc.Format = sysTexDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = 1;
	// create the resource view on the texture
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateShaderResourceView( 
		Gfx->pDevice, 
		Gfx->pSysBufferTexture,
		&srvDesc, 
		&Gfx->pSysBufferTextureView ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating view on sysBuffer texture" );
	}


	////////////////////////////////////////////////
	// create pixel shader for framebuffer
	// Ignore the intellisense error "namespace has no member"
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreatePixelShader(
		Gfx->pDevice,
		FramebufferPSBytecode,
		sizeof( FramebufferPSBytecode ),
		nullptr,
		&Gfx->pPixelShader ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating pixel shader" );
	}
	

	/////////////////////////////////////////////////
	// create vertex shader for framebuffer
	// Ignore the intellisense error "namespace has no member"
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateVertexShader(
		Gfx->pDevice,
		FramebufferVSBytecode,
		sizeof( FramebufferVSBytecode ),
		nullptr,
		&Gfx->pVertexShader ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating vertex shader" );
	}
	

	//////////////////////////////////////////////////////////////
	// create and fill vertex buffer with quad for rendering frame
	const FSQVertex vertices[] =
	{
		{ -1.0f,1.0f,0.5f,0.0f,0.0f },
		{ 1.0f,1.0f,0.5f,1.0f,0.0f },
		{ 1.0f,-1.0f,0.5f,1.0f,1.0f },
		{ -1.0f,1.0f,0.5f,0.0f,0.0f },
		{ 1.0f,-1.0f,0.5f,1.0f,1.0f },
		{ -1.0f,-1.0f,0.5f,0.0f,1.0f },
	};

	D3D11_BUFFER_DESC bd = {0};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( FSQVertex ) * 6;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0u;

	D3D11_SUBRESOURCE_DATA initData = {0};
	initData.pSysMem = vertices;
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateBuffer( 
		Gfx->pDevice,
		&bd,
		&initData,
		&Gfx->pVertexBuffer ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating vertex buffer" );
	}

	
	//////////////////////////////////////////
	// create input layout for fullscreen quad
	const D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
		{ "TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0 }
	};

	// Ignore the intellisense error "namespace has no member"
	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateInputLayout( 
		Gfx->pDevice,
		ied,2,FramebufferVSBytecode, 
		sizeof( FramebufferVSBytecode ),
		&Gfx->pInputLayout ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating input layout" );
	}


	////////////////////////////////////////////////////
	// Create sampler state for fullscreen textured quad
	D3D11_SAMPLER_DESC sampDesc = {0};
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sampDesc.MinLOD = 0;
	sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

	if( FAILED( hr = Gfx->pDevice->lpVtbl->CreateSamplerState( 
		Gfx->pDevice,
		&sampDesc,
		&Gfx->pSamplerState ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr,L"Creating sampler state" );
	}

	// allocate memory for sysbuffer (16-byte aligned for faster access)
	Gfx->pSysBuffer = ( MyColor * )_aligned_malloc( sizeof( MyColor ) * Gfx_ScreenWidth * Gfx_ScreenHeight, 16u );
}

HRESULT Gfx_EndFrame( Graphics * pGfx )
{
	HRESULT hr;

	// lock and map the adapter memory for copying over the sysbuffer
	if( FAILED( hr = pGfx->pImmediateContext->lpVtbl->Map( 
		pGfx->pImmediateContext,
		pGfx->pSysBufferTexture, 0u,
		D3D11_MAP_WRITE_DISCARD, 0u, 
		&pGfx->mappedSysBufferTexture ) ) )
	{
		return hr;
		//throw CHILI_GFX_EXCEPTION( hr, L"Mapping sysbuffer" );
	}
	// setup parameters for copy operation
	MyColor* pDst = (MyColor*)( pGfx->mappedSysBufferTexture.pData );
	const unsigned dstPitch = pGfx->mappedSysBufferTexture.RowPitch / sizeof( MyColor );
	const unsigned srcPitch = Gfx_ScreenWidth;
	const unsigned rowBytes = srcPitch * sizeof( MyColor );
	// perform the copy line-by-line
	for( unsigned y = 0u; y < Gfx_ScreenHeight; y++ )
	{
		memcpy( &pDst[ y * dstPitch ], &pGfx->pSysBuffer[ y * srcPitch ], rowBytes );
	}
	// release the adapter memory
	pGfx->pImmediateContext->lpVtbl->Unmap( pGfx->pImmediateContext, pGfx->pSysBufferTexture, 0u );

	// render offscreen scene texture to back buffer
	pGfx->pImmediateContext->lpVtbl->IASetInputLayout( pGfx->pImmediateContext, pGfx->pInputLayout );
	pGfx->pImmediateContext->lpVtbl->VSSetShader( pGfx->pImmediateContext, pGfx->pVertexShader, nullptr, 0u );
	pGfx->pImmediateContext->lpVtbl->PSSetShader( pGfx->pImmediateContext, pGfx->pPixelShader, nullptr, 0u );
	pGfx->pImmediateContext->lpVtbl->IASetPrimitiveTopology( pGfx->pImmediateContext, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
	const UINT stride = sizeof( FSQVertex );
	const UINT offset = 0u;
	pGfx->pImmediateContext->lpVtbl->IASetVertexBuffers( pGfx->pImmediateContext, 0u, 1u, &pGfx->pVertexBuffer, &stride, &offset );
	pGfx->pImmediateContext->lpVtbl->PSSetShaderResources( pGfx->pImmediateContext, 0u, 1u, &pGfx->pSysBufferTextureView );
	pGfx->pImmediateContext->lpVtbl->PSSetSamplers( pGfx->pImmediateContext, 0u, 1u, &pGfx->pSamplerState );
	pGfx->pImmediateContext->lpVtbl->Draw( pGfx->pImmediateContext, 6u, 0u );

	// flip back/front buffers
	if( FAILED( hr = pGfx->pSwapChain->lpVtbl->Present( pGfx->pSwapChain, 1u, 0u ) ) )
	{
		return hr;
		/*if( hr == DXGI_ERROR_DEVICE_REMOVED )
		{
			throw CHILI_GFX_EXCEPTION( pDevice->GetDeviceRemovedReason(), L"Presenting back buffer [device removed]" );
		}
		else
		{
			throw CHILI_GFX_EXCEPTION( hr, L"Presenting back buffer" );
		}*/
	}
}

void Gfx_BeginFrame( Graphics * pGfx )
{
	// Clear buffer
	memset( pGfx->pSysBuffer, 0u, sizeof( MyColor ) * Gfx_ScreenHeight * Gfx_ScreenWidth );
}

void Gfx_PutPixelRGB( Graphics * pGfx, int x, int y, int r, int g, int b )
{
	assert( x >= 0 );
	assert( x < ( int )( Gfx_ScreenWidth ) );
	assert( y >= 0 );
	assert( y < ( int )( Gfx_ScreenHeight ) );
	Gfx_PutPixelColor( pGfx, x, y, Color_CreateRGB( r, g, b ) );
}

void Gfx_PutPixelColor( Graphics * pGfx, int x, int y, MyColor c )
{
	assert( x >= 0 );
	assert( x < ( int )( Gfx_ScreenWidth ) );
	assert( y >= 0 );
	assert( y < ( int )( Gfx_ScreenHeight ) );
	pGfx->pSysBuffer[ Gfx_ScreenWidth * y + x ] = c;
}

void Gfx_DrawRect( Graphics * pGfx, int x0, int y0, int x1, int y1, MyColor c )
{
	if( x0 > x1 )
	{
		int t = x0;
		x0 = x1;
		x1 = t;
	}
	if( y0 > y1 )
	{
		int t = y0;
		y0 = y1;
		y1 = t;
	}

	for( int y = y0; y < y1; ++y )
	{
		for( int x = x0; x < x1; ++x )
		{
			Gfx_PutPixelColor( pGfx, x, y, c );
		}
	}
}

void Gfx_DrawRectDim( Graphics * pGfx, int x0, int y0, int width, int height, MyColor c )
{
	Gfx_DrawRect( pGfx, x0, y0, x0 + width, y0 + height, c );
}

void Gfx_DrawCircle( Graphics * pGfx, int x, int y, int radius, MyColor c )
{
	const int rad_sq = radius * radius;
	for( int y_loop = y - radius; y_loop < y + radius + 1; y_loop++ )
	{
		for( int x_loop = x - radius; x_loop < x + radius + 1; x_loop++ )
		{
			const int x_diff = x - x_loop;
			const int y_diff = y - y_loop;
			if( x_diff * x_diff + y_diff * y_diff <= rad_sq )
			{
				Gfx_PutPixelColor( pGfx, x_loop, y_loop, c );
			}
		}
	}
}

void Gfx_Destroy( Graphics * pGfx )
{
	// free sysbuffer memory (aligned free)
	if( pGfx->pSysBuffer )
	{
		_aligned_free( pGfx->pSysBuffer );
		pGfx->pSysBuffer = nullptr;
	}
	// clear the state of the device context before destruction
	if( pGfx->pImmediateContext ) 
		pGfx->pImmediateContext->lpVtbl->ClearState( pGfx->pImmediateContext );

	SafeRelease( &pGfx->pSamplerState );
	SafeRelease( &pGfx->pInputLayout );
	SafeRelease( &pGfx->pVertexBuffer );
	SafeRelease( &pGfx->pVertexShader );
	SafeRelease( &pGfx->pPixelShader );
	SafeRelease( &pGfx->pSysBufferTextureView );
	SafeRelease( &pGfx->pSysBufferTexture );
	SafeRelease( &pGfx->pRenderTargetView );
	SafeRelease( &pGfx->pSwapChain );
	SafeRelease( &pGfx->pImmediateContext );
	SafeRelease( &pGfx->pDevice );
}

