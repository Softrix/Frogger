
/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Frog Class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/


#include "Frog.h"

Frog::Frog()
{
	resetPosition();
}

// move frog
void Frog::plrMoveFrog(char key)
{
	clearFrog();

	switch (key)
	{
	case vk_left:
		if (xPos > MIN_COL)
			xPos -= 5;
		break;
	case vk_right:
		if (xPos < MAX_COL)
			xPos += 5;
		break;
	case vk_up:
		if (yPos > MIN_ROW)
			if (yPos == 52 || yPos == 29 || yPos == 26 || yPos == 3)
				yPos -= 3;
			else
				yPos -= 5;
		break;
	case vk_down:
		if (yPos < MAX_ROW && yPos  > 2)
			if (yPos == 49 || yPos == 26 || yPos == 23)
				yPos += 3;
			else
				yPos += 5;
		break;
	}
}

// update frogs xpos
void Frog::logMoveFrog(char dir)
{
	switch (dir) {
	case	'L':
		xPos--;
		break;
	case	'R':
		xPos++;
		break;
	}
}

// draw frog
void Frog::drawFrog()
{
	for (int i = xPos; i < xPos + 3; i++)
	{
		console.draw(i, yPos, green, SQUARE);
		console.draw(i, yPos + 1, green, SQUARE);
	}
}

// clear at old position of frog
void Frog::clearFrog()
{
	colour blankColour = black;  // default
	if (yPos == 52 || yPos == 26)	// pathway
		blankColour = magenta;
	else if (yPos >= 29 && yPos <= 49)	// road
			blankColour = black;
		else if (yPos >= 0 && yPos <= 23)	// water
				blankColour = darkblue;

	// redraw frog at selected colour
	for (int i = xPos; i < xPos + 3; i++) {
		console.draw(i, yPos, blankColour, SQUARE);
		console.draw(i, yPos + 1, blankColour, SQUARE);
	}
}

// reset position of frog
void Frog::resetPosition()
{
	xPos = 41;
	yPos = 52;
	ink = green;
}

