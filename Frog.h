
/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Frog class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/


#ifndef _H_FROG
#define _H_FROG

#include "Graphics.h"
#include "Object.h"

const int MAX_COL = 81;
const int MIN_COL = 1;
const int MAX_ROW = 52;
const int MIN_ROW = 0;

enum key
{
	vk_left = 75, vk_right = 77, vk_up = 72, vk_down = 80
};

class Frog : public Object
{
private:
	Graphics console;
	void clearFrog();

public:
	Frog();
	void drawFrog();
	void plrMoveFrog(char);
	void logMoveFrog(char);
	void resetPosition();
};


#endif
