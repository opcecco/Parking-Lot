#include "Collidable.h"

#include <PA9.h>

Collidable::Collidable() // Basic constructor
{
	x=-50;
	y=-50;
	startX=x;
	startY=y;
	length=0;
	width=0;
}

Collidable::Collidable(int ix,int iy,int ilength,int iwidth) // More specific constructor
{
	startX=ix;
	startY=iy;
	x=(double)ix;
	y=(double)iy;
	length=ilength;
	width=iwidth;
}

Collidable::~Collidable()
{
	
}

bool Collidable::collision(Collidable other) // Check for collision with another collidable (player, enemy, button, etc)
{
	bool colliding=false;
	if (x+length>other.x && x<other.x+other.length && y+width>other.y && y<other.y+other.width) colliding=true;
	return colliding;
}
