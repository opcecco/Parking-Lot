#include <PA9.h>
#include "all_gfx.h"

#include "Driver.h"
#include "Enemy.h"
#include "Button.h"
#include "Level.h"

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 192

bool debugMode;

bool playLevel(int currentLevel)
{
	Level level;
	Level::levelNumber=currentLevel;
	
	bool endOfGame=false;
	
	switch (currentLevel)
	{
		case 0:
			Level::lives=STARTING_LIVES;
			Level::levelNumber=0;
			endOfGame=true;
			break;
		
		// Start of level design
		
		case 1:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,50,110,HORIZONTAL,BOUNCES,5,222,-2);
			level.enemies[1]=Enemy(RANDOM_COLOR,200,60,HORIZONTAL,BOUNCES,5,222,4);
			level.enemies[2]=Enemy(RANDOM_COLOR,85,20,VERTICAL,BOUNCES,5,155,-3);
			level.enemies[3]=Enemy(RANDOM_COLOR,150,58,VERTICAL,BOUNCES,5,155,2);
			
			//level.enemies[0].button=Button(225,165,SPEEDUP,STICK,OFF);
			
			level.weather=CLOUDS_HEAVYRAIN;
			level.player=Driver(190,160);
			
			break;
		
		// End of level design
		
		default:
			Level::displayWin();
			endOfGame=true;
			break;
	}
	
	if (!endOfGame && !level.run())
	{
		Level::displayLose();
		endOfGame=true;
	}
	
	return !endOfGame;
}	

int main(int argc, char ** argv)
{
	// Initialize text, VBL, graphics, etc.
	
	PA_Init();
	PA_InitVBL();
	PA_InitText(0,0);PA_InitText(1,0);
	
	//fatInitDefault(); // Use for file system
	
	Level::loadGFX();
	
	PA_SetTextCol(1,31,31,31);
	
	// Loop all levels
	
	while (1)
	{
		playLevel(RESET);
		for (int i=1;playLevel(i);i++);
	}
	
	return 0;
}
