#include "MainWindow.h"
#include "Game.h"

int WINAPI wWinMain( HINSTANCE hInst,HINSTANCE PrevInst,LPWSTR pArgs,INT CmdShow )
{
	MainWindow wnd;
	if( !MainWindow_Create( hInst, pArgs, &wnd ) ) 
		return -1;
	Game theGame = Game_Create( &wnd );

	while( MainWindow_ProcessMessage() )
	{
		Game_Go( &theGame );
	}

	return 0;
}