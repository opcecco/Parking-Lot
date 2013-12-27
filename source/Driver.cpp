#include "Driver.h"

#include <PA9.h>
#include "all_gfx.h"

Driver::Driver() // Parameter-less constructor
{
	spriteNumber=-1;
	x=-50;
	y=-50;
	startX=x;
	startY=y;
	length=CAR_LENGTH;
	width=CAR_WIDTH;
}

Driver::Driver(int ix,int iy) // Better constructor
{
	spriteNumber=-1;
	startX=ix;
	startY=iy;
	x=(double)ix;
	y=(double)iy;
	length=CAR_LENGTH;
	width=CAR_WIDTH;
}

Driver::~Driver()
{
	//erase(); // If this line executes, the driver sprite will erase after being passed to a method due to scope technicalities (NOT GOOD!)
}

void Driver::draw(int ispriteNumber) // Draw driver sprite to screen (in original position)
{
	spriteNumber=ispriteNumber;
	PA_SetSpriteXY(0,spriteNumber,startX,startY);
	x=(double)startX;
	y=(double)startY;
}

bool Driver::drawn() // Check if driver is on screen
{
	bool drawn=true;
	if (spriteNumber<0) drawn=false;
	return drawn;
}

void Driver::erase() // Remove driver sprite from screen
{
	PA_SetSpriteXY(0,spriteNumber,-50,-50);
	return;
}

void Driver::update() // Update the driver sprite with the stylus
{
	PA_MoveSprite(spriteNumber);
	x=(double)PA_GetSpriteX(0,spriteNumber);
	y=(double)PA_GetSpriteY(0,spriteNumber);
	return;
}	
