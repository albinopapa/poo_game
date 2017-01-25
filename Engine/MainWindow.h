#pragma once
#include "ChiliWin.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <stdbool.h>
//#include "ChiliException.h"
//#include <string>

// for granting special access to hWnd only for Graphics constructor
// C doesn't have classes
typedef struct _HWNDKey
{	
	HWND hWnd;
}HWNDKey;



typedef struct _MainWindow
{
	HWNDKey key;
	Keyboard kbd;
	Mouse mouse;
	wchar_t* wndClassName;// = L"Chili DirectX Framework Window";
	HINSTANCE hInst;
	wchar_t* args;
}MainWindow;

// Constructor
bool MainWindow_Create( HINSTANCE hInst, wchar_t* pArgs, MainWindow* pWin );
// Destructor
void MainWindow_Destroy( MainWindow *pWin);

bool MainWindow_IsActive( MainWindow *pWin );
bool MainWindow_IsMinimized( MainWindow *pWin );
void MainWindow_ShowMessageBox( MainWindow *pWin, const wchar_t *pTitle, const wchar_t *pMessage );
// returns false if quitting
bool MainWindow_ProcessMessage();
const wchar_t *MainWindow_GetArgs( MainWindow *pWin );
// Next 3 may not even be necessary
LRESULT WINAPI MainWindow_HandleMsg( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

