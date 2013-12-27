#include "Enemy.h"

#include <PA9.h>
#include "all_gfx.h"

Enemy::Enemy() // Parameter-less constructor
{
	spriteNumber=-1;
	color=0;
	x=-50;
	y=-50;
	startX=x;
	startY=y;
	speed=0;
	minBound=0;
	maxBound=0;
	rotation=false;
	startRotation=rotation;
	bounces=false;
	copy=false;
	length=CAR_LENGTH;
	width=CAR_WIDTH;
}

Enemy::Enemy(int icolor,int ix,int iy,bool irotation,bool ibounces,int iminBound,int imaxBound,double ispeed) // Better constructor
{
	spriteNumber=-1;
	color=icolor;
	startX=ix;
	startY=iy;
	x=(double)ix;
	y=(double)iy;
	speed=ispeed;
	minBound=iminBound;
	maxBound=imaxBound;
	startRotation=irotation;
	rotation=startRotation;
	bounces=ibounces;
	copy=false;
	
	if (rotation)
	{
		length=CAR_WIDTH;
		width=CAR_LENGTH;
	}
	else
	{
		length=CAR_LENGTH;
		width=CAR_WIDTH;
	}
}

Enemy::~Enemy()
{
	//erase(); // If this line executes, enemies will erase after being passed to a method due to scope technicalities (NOT GOOD!)
}

void Enemy::draw(int ispriteNumber) // Draws enemy sprites to screen, called from Level class
{
	button.color=color;
	spriteNumber=ispriteNumber;
	PA_SetSpriteAnim(0,spriteNumber,color+rotation);
	PA_SetSpriteXY(0,spriteNumber,(int)startX,(int)startY);
	x=(double)startX;
	y=(double)startY;
	return;
}

bool Enemy::drawn() // Check if enemy is on screen
{
	bool drawn=true;
	if (spriteNumber<0) drawn=false;
	return drawn;
}

void Enemy::erase() // Delete Enemy sprite from screen
{
	PA_SetSpriteXY(0,spriteNumber,-50,-50);
	button.erase();
	return;
}

/* UNUSED METHOD! Keeping in case it comes in handy
void Enemy::rotate(bool irotation) // Rotates enemy perpendicular to current orientation. There have been issues with this (enemies getting stuck in walls, etc)
{
	rotation=irotation;
	
	if (rotation)
	{
		length=CAR_WIDTH;
		width=CAR_LENGTH;
	}
	else
	{
		length=CAR_LENGTH;
		width=CAR_WIDTH;
	}
	
	PA_SetSpriteAnim(0,spriteNumber,color+rotation);
	return;
}
*/

void Enemy::update() // Updates enemy sprite, called in main loop of Level class
{
	bool stopped=(button.type==GO);
	double speedMod=1.0;
	//rotate(startRotation); // See rotate(bool) method
	
	if (button.position==ON) // Check for modification in movement made by buttons
	{
		switch (button.type)
		{
			case STOP:
				stopped=true;
				break;
			case GO:
				stopped=false;
				break;
			case SPEEDUP:
				speedMod=2.0;
				break;
			case SLOWDOWN:
				speedMod=0.5;
				break;
			default:
				break;
		}
	}
	
	if (!stopped) // Move sprite across screen
	{
		if (!rotation)
		{
			if (x<=(double)minBound || x>=(double)maxBound) speed*=-1;
			x+=speed*speedMod;
			if (!copy) PA_SetSpriteX(0,spriteNumber,(int)x);
		}
		else
		{
			if (y<=(double)minBound || y>=(double)maxBound) speed*=-1;
			y+=speed*speedMod;
			if (!copy) PA_SetSpriteY(0,spriteNumber,(int)y);
		}
	}
	return;
}

Enemy Enemy::future(int frames) // Extrapolate the future state of the enemy, used by Level class to prevent collisions
{
	Enemy future=*this; // Woo pointers! (So much time spent debugging such little code)
	future.copy=true;
	for (int i=0;i<frames;i++) future.update();
	return future;
}
