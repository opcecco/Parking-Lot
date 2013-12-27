#pragma once

#include "Collidable.h"

class Driver: public Collidable
{
	public:
		int spriteNumber;
		
		Driver();
		Driver(int,int);
		~Driver();
		void draw(int);
		bool drawn();
		void erase();
		void update();
};
