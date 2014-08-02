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
			
			level.enemies[0]=Enemy(RANDOM_COLOR,28,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[1]=Enemy(RANDOM_COLOR,94,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[2]=Enemy(RANDOM_COLOR,164,88,HORIZONTAL,STOPS,0,0,0);
			
			//level.enemies[0].button=Button(225,165,SPEEDUP,STICK,OFF);
			
			//level.weather=HEAVYCLOUDS_HEAVYRAIN;
			level.player=Driver(209,169);
			break;
			
		case 2:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,50,85,HORIZONTAL,STOPS,5,222,3);
			
			level.player=Driver(209,169);
			break;
			
		case 3:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,40,80,HORIZONTAL,STOPS,5,222,2);
			level.enemies[1]=Enemy(RANDOM_COLOR,92,105,HORIZONTAL,STOPS,5,222,-3);
			
			level.player=Driver(209,169);
			break;
			
		case 4:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,10,75,HORIZONTAL,STOPS,5,222,3);
			level.enemies[1]=Enemy(RANDOM_COLOR,200,100,HORIZONTAL,STOPS,5,222,1);
			level.enemies[2]=Enemy(RANDOM_COLOR,134,125,HORIZONTAL,STOPS,5,222,-2);
			
			level.player=Driver(209,169);
			break;
			
		case 5:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,25,120,HORIZONTAL,STOPS,5,222,3);
			level.enemies[1]=Enemy(RANDOM_COLOR,80,60,VERTICAL,STOPS,5,155,-2);
			level.enemies[2]=Enemy(RANDOM_COLOR,175,55,HORIZONTAL,STOPS,0,0,0);
			
			level.player=Driver(209,169);
			break;
			
		case 6:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,50,110,HORIZONTAL,STOPS,5,222,-2);
			level.enemies[1]=Enemy(RANDOM_COLOR,150,60,HORIZONTAL,STOPS,5,222,4);
			level.enemies[2]=Enemy(RANDOM_COLOR,85,20,VERTICAL,STOPS,5,155,-3);
			level.enemies[3]=Enemy(RANDOM_COLOR,150,100,VERTICAL,STOPS,5,155,2);
			
			level.player=Driver(209,169);
			break;
			
		case 7:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,6,52,HORIZONTAL,BOUNCES,5,222,4);
			level.enemies[1]=Enemy(RANDOM_COLOR,222,115,HORIZONTAL,BOUNCES,5,222,4);
			level.enemies[2]=Enemy(RANDOM_COLOR,100,82,HORIZONTAL,BOUNCES,5,222,5);
			level.enemies[3]=Enemy(RANDOM_COLOR,70,80,VERTICAL,STOPS,5,155,-5);
			
			level.player=Driver(209,169);
			break;
			
		case 8:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,75,120,VERTICAL,BOUNCES,5,155,5);
			level.enemies[1]=Enemy(RANDOM_COLOR,102,150,VERTICAL,BOUNCES,5,155,-4);
			level.enemies[2]=Enemy(RANDOM_COLOR,150,134,HORIZONTAL,STOPS,128,222,1);
			level.enemies[3]=Enemy(RANDOM_COLOR,178,108,HORIZONTAL,STOPS,128,222,-2);
			level.enemies[4]=Enemy(RANDOM_COLOR,10,82,HORIZONTAL,STOPS,5,90,3);
			
			level.weather=RAIN;
			level.player=Driver(209,169);
			break;
			
		/* case 9:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,28,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[1]=Enemy(RANDOM_COLOR,94,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[2]=Enemy(RANDOM_COLOR,164,88,HORIZONTAL,STOPS,0,0,0);
			
			level.player=Driver(209,169);
			break;
			
		case 10:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,28,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[1]=Enemy(RANDOM_COLOR,94,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[2]=Enemy(RANDOM_COLOR,164,88,HORIZONTAL,STOPS,0,0,0);
			
			level.player=Driver(209,169);
			break;
			
		case 11:
			
			level.enemies[0]=Enemy(RANDOM_COLOR,28,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[1]=Enemy(RANDOM_COLOR,94,88,HORIZONTAL,STOPS,0,0,0);
			level.enemies[2]=Enemy(RANDOM_COLOR,164,88,HORIZONTAL,STOPS,0,0,0);
			
			level.player=Driver(209,169);
			break; */
			
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
