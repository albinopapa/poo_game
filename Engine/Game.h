#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Poo.h"
#include "Dude.h"
#include "Goal.h"
#include "Meter.h"
// TODO: Finish Sound stuff
//#include "SoundEffect.h"
#include "FrameTimer.h"
#include "MainWindow.h"


typedef struct _Game
{
	MainWindow* wnd;
	Graphics gfx;

	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	Dude dude;
	Goal goal;
	Meter meter;
	Poo poos[ 10 ];
	bool isStarted;
	bool isGameOver;
	bool isInitialized;

	/*SoundEffect pickup = SoundEffect( { L"Sounds\\coin.wav" } );
	Sound title = Sound( L"Sounds\\title.wav" );
	SoundEffect fart = SoundEffect( 
		{ L"Sounds\\fart1.wav",L"Sounds\\fart2.wav" } );*/
	/********************************/
}Game;

Game Game_Create( struct MainWindow* wnd );
void Game_Go( Game *pGame );
void Game_ComposeFrame( Game *pGame );
void Game_UpdateModel( Game *pGame );
	/********************************/
	/*  User Functions              */
void Game_DrawGameOver( Graphics *gfx, int x, int y );
void Game_DrawTitleScreen( Graphics *gfx, int x, int y );
	/********************************/
