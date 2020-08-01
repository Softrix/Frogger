
/*

		$file:						graphics class
		$purpose:					console stuff to colour, reposition cursor etc.
		$author:					Kyle Lanmon / Michael Boyle (Softrix)

*/


#include "Graphics.h"

// constructor
Graphics::Graphics()
{
	coordScreen.X = 0;
	coordScreen.Y = 0;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	setColour(green);
}

// set text colour
void Graphics::setColour(colour ink)
{
	SetConsoleTextAttribute(hConsoleOutput, ink);
}

// draw character c at x,y pos and colour ink
void Graphics::draw(int x, int y, colour ink, char c)
{
	setColour(ink);
	coordScreen.X = x;
	coordScreen.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, coordScreen);
	std::cout << c;
	std::cout.flush();
}

// position cursor
void Graphics::move(int x, int y)
{
	coordScreen.X = x;
	coordScreen.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, coordScreen);
}

// resize console window
void Graphics::setConsoleSize(int rows, int columns)
{
	_SMALL_RECT rect;
	coordScreen.X = columns;
	coordScreen.Y = rows;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = rows - 1;
	rect.Right = columns - 1;
	SetConsoleScreenBufferSize(hConsoleOutput, coordScreen);
	SetConsoleWindowInfo(hConsoleOutput, TRUE, &rect);
}

void Graphics::drawWorld()
{
	// river
	for (int i = 0; i < 85; i++)
		for (int k = 0; k < 26; k++)
			draw(i, k, darkblue, SQUARE);

	// pavement
	for (int i = 0; i < 85; i++)
	{
		draw(i, 26, magenta, SQUARE);
		draw(i, 27, magenta, SQUARE);
		draw(i, 52, magenta, SQUARE);
		draw(i, 53, magenta, SQUARE);
	}

	// street/road
	for (int i = 0; i < 85; i++)
	{
		if (i < 5) 	{
			draw(i, 32, yellow, SQUARE);
			draw(i, 37, yellow, SQUARE);
			draw(i, 42, yellow, SQUARE);
			draw(i, 47, yellow, SQUARE);
		}

		if ((i >= 10 && i < 15) || (i >= 20 && i < 25) || (i >= 30 && i < 35) || (i >= 40 && i < 45)) {
			draw(i, 32, yellow, SQUARE);
			draw(i, 37, yellow, SQUARE);
			draw(i, 42, yellow, SQUARE);
			draw(i, 47, yellow, SQUARE);
		}

		if ((i >= 50 && i < 55) || (i >= 60 && i < 65) || (i >= 70 && i < 75) || (i >= 80 && i < 85)) {
			draw(i, 32, yellow, SQUARE);
			draw(i, 37, yellow, SQUARE);
			draw(i, 42, yellow, SQUARE);
			draw(i, 47, yellow, SQUARE);
		}
	}

	// winzones
	for (int offset = 0; offset <= 80; offset += 20)
		for (int col = offset; col < offset + 5; col++)
		{
			draw(col, 0, purple, SQUARE);
			draw(col, 1, purple, SQUARE);
		}

}