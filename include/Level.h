#pragma once

#include "Collidable.h"
#include "Driver.h"
#include "Enemy.h"
#include "Button.h"

#define NONE 0
#define RAIN 1
#define HEAVYRAIN 2
#define CLOUDS 3
#define HEAVYCLOUDS 4
#define CLOUDS_RAIN 5
#define CLOUDS_HEAVYRAIN 6
#define HEAVYCLOUDS_RAIN 7
#define HEAVYCLOUDS_HEAVYRAIN 8

#define STARTING_LIVES 5

#define MIN_PLAYER_SPRITE 0
#define MAX_PLAYER_SPRITE 4
#define MIN_ENEMY_SPRITE 5
#define MAX_ENEMY_SPRITE 24
#define MIN_BUTTON_SPRITE 25
#define MAX_BUTTON_SPRITE 44

#define RESET 0

class Level
{
	public:
		static int lives,levelNumber;
		int weather;
		Driver player;
		Enemy enemies[(MAX_ENEMY_SPRITE+1)-MIN_ENEMY_SPRITE];
		
		static void loadGFX();
		static void displayLose();
		static void displayWin();
		Level();
		Level(Driver,Enemy[],int);
		bool run();
};
