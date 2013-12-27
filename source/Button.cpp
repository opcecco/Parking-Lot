#include "Button.h"

#include <PA9.h>
#include "all_gfx.h"

Button::Button() // Parameter-less constructor
{
	spriteNumber=-1;
	color=0;
	x=-50;
	y=-50;
	startX=x;
	startY=y;
	type=INEFFECTIVE;
	pressType=CLICK;
	length=BUTTON_LENGTH;
	width=BUTTON_WIDTH;
	position=OFF;
}

Button::Button(int ix,int iy,int itype,bool ipressType,bool iposition) // Better constructor
{
	spriteNumber=-1;
	color=0;
	startX=ix;
	startY=iy;
	x=(double)ix;
	y=(double)iy;
	type=itype;
	pressType=ipressType;
	length=BUTTON_LENGTH;
	width=BUTTON_WIDTH;
	position=iposition;
}

Button::~Button()
{
	//erase(); // If this line executes, the button sprite will erase after being passed to a method due to scope technicalities (NOT GOOD!)
}

void Button::draw(int ispriteNumber) // Draw button to screen
{
	spriteNumber=ispriteNumber;
	PA_SetSpriteAnim(0,spriteNumber,color+position);
	PA_SetSpriteXY(0,spriteNumber,(int)startX,(int)startY);
	x=(double)startX;
	y=(double)startY;
}

bool Button::drawn() // Check if button is on screen
{
	bool drawn=true;
	if (spriteNumber<0) drawn=false;
	return drawn;
}

void Button::erase() // Remove button from screen
{
	PA_SetSpriteXY(0,spriteNumber,-50,-50);
	return;
}

void Button::switchTo(bool iposition) // Put the button in the ON or OFF position
{
	position=iposition;
	draw(spriteNumber);
	return;
}

void Button::update() // Update(?) the button
{
	// Possibly no code goes here
	return;
}
