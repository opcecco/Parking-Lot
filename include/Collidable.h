#pragma once

#define MAX_COLORS 15

#define WHITE 0
#define RED 2
#define ORANGE 4
#define YELLOW 6
#define GREEN 8
#define CYAN 10
#define BLUE 12
#define VIOLET 14
#define BRICK 16
#define GOLD 18
#define FOREST 10
#define COBALT 22
#define NAVY 24
#define PINK 26
#define LIME 28

#define RANDOM_COLOR PA_RandMinMax(0,MAX_COLORS-1)*2

#define HORIZONTAL 0
#define VERTICAL 1

#define CAR_LENGTH 32
#define CAR_WIDTH 16

#define BUTTON_LENGTH 8
#define BUTTON_WIDTH 8

#define STOPS 0
#define BOUNCES 1

class Collidable
{
	public:
		int length,width,startX,startY;
		double x,y;
		
		Collidable();
		Collidable(int,int,int,int);
		~Collidable();
		bool collision(Collidable);
};
