/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Logs Class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/


#include "Logs.h"

Log::Log()
{
	// default values.
	xPos = 0;
	yPos = 0;
	speed = 0;
	size = 0;
	dir = 0;
	ink = black;
}

// initialise log
void Log::setLog(int x, int y, int delay, int len, char direction, colour c)
{
	xPos = x;
	yPos = y;
	speed = delay;
	timer = delay;
	ink = c;
	size = len;
	dir = direction;
}

// update position of log
void Log::updateLog()
{
	timer--;
	if (timer == 0) {
		// reset the timer.
		timer = speed;
		// what direction?
		switch (dir)
		{
		case 'L':  // moving left
			clearLog();
			xPos--;
			if (xPos <= 0) {
				xPos = 85 - size;
			}
			drawLog();
			break;
		case 'R':  // moving right.
			clearLog();
			xPos++;
			if (xPos >= 85 - size) {
				xPos = 0;
			}
			drawLog();
			break;
		} 
	}
}

void Log::drawLog()
{
	for (int i = 0; i < size; i++) {
		console.draw(xPos + i, yPos, ink, SQUARE);
		console.draw(xPos + i, yPos+1, ink, SQUARE);
	}
}

void Log::clearLog()
{
	for (int i = 0; i < size; i++) {
		console.draw(xPos + i, yPos, darkblue, SQUARE);
		console.draw(xPos + i, yPos+1, darkblue, SQUARE);
	}
}