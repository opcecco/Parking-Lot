#pragma once

#include "Collidable.h"

#define INEFFECTIVE 0
#define STOP 1
#define GO 2
#define SPEEDUP 3
#define SLOWDOWN 4

#define CLICK 0
#define STICK 1

#define OFF 0
#define ON 1

class Button: public Collidable
{
	public:
		int spriteNumber,color,type;
		bool pressType,pressed,position;
		
		Button();
		Button(int,int,int,bool,bool);
		~Button();
		void draw(int);
		bool drawn();
		void erase();
		void switchTo(bool);
		void update();
};
