
/*

		$file:						graphics class
		$purpose:					console stuff to colour, reposition cursor etc.
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/


#ifndef _H_GRAPHICS
#define _H_GRAPHICS

#include <Windows.h>
#include <iostream>

const unsigned char SQUARE = 219;
const unsigned char LEFT = 221;
const unsigned char RIGHT = 222;
const unsigned char TOP = 223;
const unsigned char BOTTOM = 220;
const unsigned char BLANK = ' ';
const unsigned char SNOWMAN = '*';

enum colour
{
	black = 0x00, darkblue = 0x01, darkgreen = 0x02, darkcyan = 0x03,
	darkred = 0x04, purple = 0x05, darkyellow = 0x06, lightgrey = 0x07,
	grey = 0x08, blue = 0x09, green = 0x0A, cyan = 0x0B,
	red = 0x0C, magenta = 0x0D, yellow = 0x0E, white = 0x0F
};

class Graphics
{
protected:
	COORD coordScreen;
	HANDLE hConsoleOutput;
private:
public:
	Graphics();
	void setConsoleSize(int, int);
	void setColour(colour);
	void draw(int, int, colour, char);
	void drawWorld();
	void move(int, int);
};

#endif // !_H_GRAPHICS
