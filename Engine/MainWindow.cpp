#include "MainWindow.h"
#include "Resource.h"
#include "Graphics.h"
#include "Game.h"
#include <assert.h>

bool MainWindow_Create( HINSTANCE hInst, wchar_t * pArgs, MainWindow* pWin )
{
	pWin->hInst = hInst;
	pWin->args = pArgs;
	pWin->wndClassName = L"MyClass";

	// register window class
	WNDCLASSEX wc = { sizeof( WNDCLASSEX ),CS_CLASSDC,MainWindow_HandleMsg,0,0,
		pWin->hInst,NULL,NULL,NULL,NULL,
		pWin->wndClassName,NULL };
	wc.hIconSm = ( HICON )LoadImage( pWin->hInst, MAKEINTRESOURCE( IDI_APPICON ), IMAGE_ICON, 16, 16, 0 );
	wc.hIcon = ( HICON )LoadImage( pWin->hInst, MAKEINTRESOURCE( IDI_APPICON ), IMAGE_ICON, 32, 32, 0 );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	RegisterClassEx( &wc );

	// create window & get hWnd
	const int left = 350;
	const int top = 100;
	RECT wr;
	SetRect( &wr, left, top, Gfx_ScreenWidth + left, Gfx_ScreenHeight + top );
	AdjustWindowRect( &wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE );
	const int width = wr.right - wr.left;
	const int height = wr.bottom - wr.top;

	pWin->key.hWnd = CreateWindow( pWin->wndClassName, L"Chili DirectX Framework",
								 WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
								 wr.left, wr.top, 
								 width, height,
								 NULL, NULL, pWin->hInst, pWin );

	// throw exception if something went terribly wrong
	if( pWin->key.hWnd == NULL )
	{
		/*throw Exception( _CRT_WIDE( __FILE__ ), __LINE__,
						 L"Failed to get valid window handle." );*/
		return FALSE;
	}

	// show and update
	ShowWindow( pWin->key.hWnd, SW_SHOWDEFAULT );
	UpdateWindow( pWin->key.hWnd );

	pWin->mouse = Mouse_Create();
	pWin->kbd = Kbd_Create();

	return TRUE;
}

void MainWindow_Destroy( MainWindow * pWin )
{
	// unregister window class
	UnregisterClass( pWin->wndClassName, pWin->hInst );
}

bool MainWindow_IsActive( MainWindow * pWin )
{
	return GetActiveWindow() == pWin->key.hWnd;
}

bool MainWindow_IsMinimized( MainWindow * pWin )
{
	return IsIconic( pWin->key.hWnd ) != 0;
}

void MainWindow_ShowMessageBox( MainWindow * pWin, const wchar_t * pTitle, const wchar_t * pMessage )
{
	MessageBox( pWin->key.hWnd, pMessage, pTitle, MB_OK );
}

bool MainWindow_ProcessMessage()
{
	MSG msg;
	while( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
		if( msg.message == WM_QUIT )
		{
			return false;
		}
	}
	return true;
}

const wchar_t * MainWindow_GetArgs( MainWindow * pWin )
{
	return pWin->args;
}


LRESULT WINAPI MainWindow_HandleMsg( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	MainWindow* pWnd = 0;
	// use create parameter passed in from CreateWindow() to store window class pointer at WinAPI side
	if( msg == WM_NCCREATE )
	{
		// extract ptr to window class from creation data
		const CREATESTRUCTW* const pCreate = (CREATESTRUCTW*)lParam;
		pWnd = ( MainWindow* )pCreate->lpCreateParams;
		// sanity check
		assert( pWnd != NULL );
		// set WinAPI-managed user data to store ptr to window class
		SetWindowLongPtr( hWnd,GWLP_USERDATA,( LONG_PTR )pWnd );
	}
	else
	{
		pWnd = ( MainWindow* )GetWindowLongPtr( hWnd, GWLP_USERDATA );
	}

	if( !pWnd )
	{
		return DefWindowProc( hWnd, msg, wParam, lParam );
	}

	switch( msg )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );
		break;
	
		// ************ KEYBOARD MESSAGES ************ //
	case WM_KEYDOWN:
		if( !( lParam & 0x40000000 ) || Kbd_AutorepeatIsEnabled( &pWnd->kbd ) ) // no thank you on the autorepeat
		{
			Kbd_OnKeyPressed( &pWnd->kbd, ( unsigned char )wParam );
		}
		break;
	case WM_KEYUP:
		Kbd_OnKeyReleased( &pWnd->kbd, ( unsigned char )wParam );
		break;
	case WM_CHAR:
		Kbd_OnChar( &pWnd->kbd, ( char )wParam );
		break;
		// ************ END KEYBOARD MESSAGES ************ //
	
		// ************ MOUSE MESSAGES ************ //
	case WM_MOUSEMOVE:
	{
		POINTS pt = MAKEPOINTS( lParam );
		if( pt.x > 0 && pt.x < Gfx_ScreenWidth && 
			pt.y > 0 && pt.y < Gfx_ScreenHeight )
		{
			Mouse_OnMouseMove( &pWnd->mouse, pt.x, pt.y );
			if( Mouse_IsInWindow( &pWnd->mouse ) )
			{
				SetCapture( hWnd );
				Mouse_OnMouseEnter( &pWnd->mouse );
			}
		}
		else
		{
			if( wParam & (MK_LBUTTON | MK_RBUTTON) )
			{
				pt.x = max( ( short )0, pt.x );
				pt.x = min( ( short )Gfx_ScreenWidth - 1, pt.x );
				pt.y = max( ( short )0, pt.y );
				pt.y = min( ( short )Gfx_ScreenHeight - 1, pt.y );
				Mouse_OnMouseMove( &pWnd->mouse, pt.x, pt.y );
			}
			else
			{
				ReleaseCapture();
				Mouse_OnMouseLeave( &pWnd->mouse );
				Mouse_OnLeftPressed( &pWnd->mouse, pt.x, pt.y );
				Mouse_OnLeftReleased( &pWnd->mouse, pt.x, pt.y );
				Mouse_OnRightReleased( &pWnd->mouse, pt.x, pt.y );
			}
		}
		break;
	}
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS( lParam );
		Mouse_OnLeftPressed( &pWnd->mouse, pt.x, pt.y );
		break;
	}
	case WM_RBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS( lParam );
		Mouse_OnRightPressed( &pWnd->mouse, pt.x, pt.y );
		break;
	}
	case WM_LBUTTONUP:
	{
		const POINTS pt = MAKEPOINTS( lParam );
		Mouse_OnLeftReleased( &pWnd->mouse, pt.x, pt.y );
		break;
	}
	case WM_RBUTTONUP:
	{
		const POINTS pt = MAKEPOINTS( lParam );
		Mouse_OnRightReleased( &pWnd->mouse, pt.x, pt.y );
		break;
	}
	case WM_MOUSEWHEEL:
	{
		const POINTS pt = MAKEPOINTS( lParam );
		if( GET_WHEEL_DELTA_WPARAM( wParam ) > 0 )
		{
			Mouse_OnWheelUp( &pWnd->mouse, pt.x,pt.y );
		}
		else if( GET_WHEEL_DELTA_WPARAM( wParam ) < 0 )
		{
			Mouse_OnWheelDown( &pWnd->mouse, pt.x,pt.y );
		}
		break;
	}
	// ************ END MOUSE MESSAGES ************ //
	}
	
	return DefWindowProc( hWnd,msg,wParam,lParam );
}
