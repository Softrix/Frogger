
/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Cars Class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/



#include "Cars.h"

// constructor
Car::Car()
{
	xPos = 0;
	yPos = 0;
	speed = 0;
	timer = 0;
	size = 0;
	dir = 'R';
	ink = black;
}

// initialise car
void Car::setCar(int x, int y, int delay, int len, char direction, colour c)
{
	xPos = x;
	yPos = y;
	speed = delay;
	timer = delay;
	ink = c;
	size = len;
	dir = direction;
}

// update car
void Car::updateCar()
{
	timer--;
	if (timer == 0) {
		// reset the timer.
		timer = speed;
		// what direction?
		switch (dir)
		{
		case 'L':  // moving left
			clearCar();
			xPos--;
			if (xPos <= 0) {
				xPos = 85 - size;
			}
			drawCar();
			break;
		case 'R':  // moving right.
			clearCar();
			xPos++;
			if (xPos >= 85 - size) {
				xPos = 0;
			}
			drawCar();
			break;
		}
	}
}

// clear last car position
void Car::clearCar()
{
	for (int i = 0; i < size; i++) {
		console.draw(xPos + i, yPos, black, SQUARE);
		console.draw(xPos + i, yPos + 1, black, SQUARE);
	}
}

void Car::drawCar()
{
	for (int i = 0; i < size; i++) {
		console.draw(xPos + i, yPos, ink, SQUARE);
		console.draw(xPos + i, yPos + 1, ink, SQUARE);
	}
}