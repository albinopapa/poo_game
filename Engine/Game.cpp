#include "Game.h"
#include <time.h>
const int Game_nPoo = 10;

Game Game_Create( MainWindow* wnd )
{
	srand( time( NULL ) );
	Game g;
	g.wnd = wnd;
	
	if( !Gfx_Create( &wnd->key, &g.gfx ) )
	{
		g.isInitialized = false;
		return g;
	}

	// Create goal
	Vec2 goalPos = Vec_Create( (float)( rand() % 770 ), (float)( rand() % 570 ));
	g.goal = Goal_Create( &goalPos );

	// Create meter
	g.meter = Meter_Create( 20, 20 );

	// Create poo velocity between -150 and 150 pixels per second
	const int range = 30000;
	const int half_range = range >> 1;
	for( int i = 0; i < Game_nPoo; ++i )
	{
		const float px = ( float )( rand() % 770 );
		const float py = ( float )( rand() % 570 );
		const float vx = ( float )( ( rand() % range ) - half_range ) * .01f;
		const float vy = ( float )( ( rand() % range ) - half_range ) * .01f;
		Vec2 pos = Vec_Create( px, py );
		const Vec2 vel = Vec_Create( vx, vy );
		g.poos[i] = Poo_Create( &pos, &vel );
	}

	// Dude
	g.dude = Dude_Create( 
		( float )( Gfx_ScreenWidth >> 1 ), 
		( float )( Gfx_ScreenHeight >> 1 ) 
	);

	// Initialize the frame timer
	g.ft = Timer_Create();

	// Initialize the game
	g.isInitialized = true;
	g.isStarted = true;
	g.isGameOver = false;
	
	return g;
	//title.Play();
}

void Game_Go( Game *pGame )
{
	Gfx_BeginFrame( &pGame->gfx );
	Game_UpdateModel( pGame );
	Game_ComposeFrame( pGame );
	Gfx_EndFrame( &pGame->gfx );
}

void Game_UpdateModel( Game *pGame )
{
	const float dt = Timer_Mark( &pGame->ft );

	Goal_UpdateColor( &pGame->goal );

	if( pGame->isStarted && !pGame->isGameOver )
	{
		Dude_UpdateMouse( &pGame->dude, &pGame->wnd->mouse, dt );
		Dude_ClampToScreen( &pGame->dude );

		for( int i = 0; i < Game_nPoo; ++i )
		{
			Poo_Update( &pGame->poos[ i ], dt );
			if( Poo_TestCollision( &pGame->poos[ i ], &pGame->dude ) )
			{
				pGame->isGameOver = true;
				//fart.Play( rng );
			}
		}
		if( Goal_TestCollision(&pGame->goal, &pGame->dude ) )
		{
			const float px = ( float )( rand() % 770 );
			const float py = ( float )( rand() % 570 );
			const Vec2 pos = Vec_Create( px, py );
			Goal_Respawn( &pGame->goal, &pos );
			Meter_IncreaseLevel( &pGame->meter );
			//pickup.Play( rng );
		}		
	}
	else
	{
		if( Kbd_KeyIsPressed(&pGame->wnd->kbd, VK_RETURN ) )
		{
			pGame->isStarted = true;
		}
	}
}

void Game_ComposeFrame( Game *pGame )
{
	if( !pGame->isStarted )
	{
		Game_DrawTitleScreen( pGame, 325, 211 );
	}
	else
	{
		Goal_Draw( &pGame->goal, &pGame->gfx );

		for( int i = 0; i < Game_nPoo; ++i )
		{
			Poo_Draw( &pGame->poos[ i ], &pGame->gfx );
		}

		Dude_Draw( &pGame->dude, &pGame->gfx );
		if( pGame->isGameOver )
		{
			Game_DrawGameOver( &pGame->gfx, 358, 268 );
		}
		Meter_Draw( &pGame->meter, &pGame->gfx );
	}
}
