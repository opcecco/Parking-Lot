#include "Level.h"

#include <PA9.h>
#include "all_gfx.h"

int Level::lives=STARTING_LIVES;
int Level::levelNumber=0;

void Level::loadGFX() // Load all graphics from PAGFX generated code
{
	/*
		Background priorities:
		3 - parking lot
		  - buttons / obstacles
		2 - 
		  - cars
		1 - rain
		  - 
		0 - clouds
		  - 
	*/
	
	PA_LoadSpritePal(0,0,(void*)player_Pal);
	PA_LoadSpritePal(0,1,(void*)enemy_Pal);
	PA_LoadSpritePal(0,2,(void*)button_Pal);
	
	for (int i=MIN_PLAYER_SPRITE;i<=MAX_PLAYER_SPRITE;i++) // Allocate all player sprites
	{
		PA_CreateSprite(0,i,(void*)player_Sprite,OBJ_SIZE_32X16,1,0,-50,-50);
		PA_SetSpritePrio(0,i,2);
	}
	
	for (int i=MIN_ENEMY_SPRITE;i<=MAX_ENEMY_SPRITE;i++) // Allocate all enemy sprites
	{
		PA_CreateSprite(0,i,(void*)enemy_Sprite,OBJ_SIZE_32X32,1,1,-50,-50);
		PA_SetSpritePrio(0,i,2);
	}
	
	for (int i=MIN_BUTTON_SPRITE;i<=MAX_BUTTON_SPRITE;i++) // Allocate all button sprites
	{
		PA_CreateSprite(0,i,(void*)button_Sprite,OBJ_SIZE_8X8,1,2,-50,-50);
		PA_SetSpritePrio(0,i,3);
	}
	
	PA_LoadBackground(0,3,&parkinglotbg);
	PA_LoadBackground(1,3,&topscreenbg);
	
	return;
}

void Level::displayLose() // Called when player crashes
{
	PA_LoadBackground(0,1,&gameoverbg);
	while (!Stylus.Newpress) PA_WaitForVBL();
	PA_DeleteBg(0,1);
	return;
}

void Level::displayWin() // Called when player completes all levels
{
	PA_LoadBackground(0,1,&congratsbg);
	while (!Stylus.Newpress) PA_WaitForVBL();
	PA_DeleteBg(0,1);
	return;
}

Level::Level() // Parameter-less constructor
{
	weather=0;
}

Level::Level(Driver iplayer,Enemy ienemies[(MAX_ENEMY_SPRITE+1)-MIN_ENEMY_SPRITE],int iweather) // Better constructor
{
	player=iplayer;
	for (int i=0;i<=MAX_ENEMY_SPRITE-MIN_ENEMY_SPRITE;i++) enemies[i]=ienemies[i];
	weather=iweather;
}

bool Level::run() // Called from main.cpp after level variables have been set
{
	bool success=false;
	
	switch (weather) // Load appropriate weather for level
	{
		case NONE:
			break;
		case RAIN:
			PA_LoadBackground(0,1,&rainbg);
			break;
		case HEAVYRAIN:
			PA_LoadBackground(0,1,&heavyrainbg);
			break;
		case CLOUDS:
			PA_LoadBackground(0,0,&cloudsbg);
			break;
		case HEAVYCLOUDS:
			PA_LoadBackground(0,0,&heavycloudsbg);
			break;
		case CLOUDS_RAIN:
			PA_LoadBackground(0,0,&cloudsbg);
			PA_LoadBackground(0,1,&rainbg);
			break;
		case CLOUDS_HEAVYRAIN:
			PA_LoadBackground(0,0,&cloudsbg);
			PA_LoadBackground(0,1,&heavyrainbg);
			break;
		case HEAVYCLOUDS_RAIN:
			PA_LoadBackground(0,0,&heavycloudsbg);
			PA_LoadBackground(0,1,&rainbg);
			break;
		case HEAVYCLOUDS_HEAVYRAIN:
			PA_LoadBackground(0,0,&heavycloudsbg);
			PA_LoadBackground(0,1,&heavyrainbg);
			break;
		default:
			break;
	}
	
	// Draw all sprites and set arbitrary variables
	player.draw(MIN_PLAYER_SPRITE);
	
	for (int i=0;i<=MAX_ENEMY_SPRITE-MIN_ENEMY_SPRITE;i++)
	{
		if (!(enemies[i].x<=-50 && enemies[i].y<=-50)) enemies[i].draw(i+MIN_ENEMY_SPRITE);
		if (!(enemies[i].button.x<=-50 && enemies[i].button.y<=-50)) enemies[i].button.draw(i+MIN_BUTTON_SPRITE);
	}
	
	int rainBgScrollX=0,rainBgScrollY=0,cloudsBgScrollX=0,cloudsBgScrollY=0;
	
	Collidable goal(0,0,44,30); // Create goal as an invisible Collidable
	
	while (lives>0 && !success) // Main level loop
	{
		player.update();
		
		for (int i=0;i<=MAX_ENEMY_SPRITE-MIN_ENEMY_SPRITE;i++)
		{
			if (enemies[i].drawn())
			{
				if (player.collision(enemies[i])) // If player crashes
				{
					// **ADD** crashing sound
					if (!Stylus.Held)
					{
						while (!Stylus.Held) PA_WaitForVBL();
					}
					while (Stylus.Held) PA_WaitForVBL();
					
					lives--;
					player.draw(player.spriteNumber); // Redraw player at start
				}
				
				if (enemies[i].button.drawn()) // If player presses a button
				{
					if (enemies[i].button.pressType==CLICK)
					{
						if (player.collision(enemies[i].button))
						{
							// **ADD** clicking sound
							enemies[i].button.pressed=true;
							enemies[i].button.switchTo(ON);
						}
						else
						{
							// **ADD** clicking sound
							enemies[i].button.pressed=false;
							enemies[i].button.switchTo(OFF);
						}
					}
					
					if (enemies[i].button.pressType==STICK)
					{
						if (player.collision(enemies[i].button) && enemies[i].button.pressed==false)
						{
							// **ADD** clicking sound
							enemies[i].button.pressed=true;
							enemies[i].button.switchTo(!enemies[i].button.position);
						}
						
						if (!player.collision(enemies[i].button)) enemies[i].button.pressed=false;
					}
				}
				
				// Check if enemies will collide
				bool needsToStop=false;
				for (int j=0;j<=(MAX_ENEMY_SPRITE+1)-MIN_ENEMY_SPRITE;j++)
				{
					if (i!=j && enemies[j].drawn())
					{
						if (enemies[i].future(2).collision(enemies[j]))
						{
							if (enemies[i].bounces) enemies[i].speed*=-1;
							else needsToStop=true;
							break;
						}
					}
				}
				if (!needsToStop) enemies[i].update();
			}
		}
		
		if (!Stylus.Held && player.collision(goal)) // Break loop when player hits the goal
		{
			success=true;
		}
		
		// Update weather effects
		cloudsBgScrollX-=1;PA_EasyBgScrollXY(0,0,cloudsBgScrollX,cloudsBgScrollY);
		rainBgScrollX-=3;rainBgScrollY-=3;PA_EasyBgScrollXY(0,1,rainBgScrollX,rainBgScrollY);
		
		// Text info on top screen
		PA_OutputText(1,4,2,"Level: %d    ",levelNumber);PA_OutputText(1,16,2,"Lives: %d    ",lives);
		
		PA_WaitForVBL();
	}
	
	// After level finishes, erase all sprites and weather effects
	for (int i=0;i<=MAX_ENEMY_SPRITE-MIN_ENEMY_SPRITE;i++) enemies[i].erase();
	player.erase();
	
	PA_DeleteBg(0,0);
	PA_DeleteBg(0,1);
	PA_DeleteBg(0,2);
	
	PA_WaitForVBL(); // Update screen after erasing sprites ... for good measure ;)
	
	return success;
}
