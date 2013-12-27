#pragma once

#include "Collidable.h"
#include "Button.h"

class Enemy: public Collidable
{
	public:
		int spriteNumber,color,minBound,maxBound;
		double speed;
		bool rotation,startRotation,bounces,copy;
		Button button;
		
		Enemy();
		Enemy(int,int,int,bool,bool,int,int,double);
		~Enemy();
		void draw(int);
		bool drawn();
		void erase();
		void rotate(bool);
		void update();
		Enemy future(int);
};
