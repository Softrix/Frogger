
/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Frogger Game Engine
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/


#ifndef _H_ENGINE
#define _H_ENGINE

#include <Windows.h>
#include <conio.h>
#include "Graphics.h"
#include "Ascii.h"
#include "Logs.h"
#include "Cars.h"
#include "Frog.h"

class Engine
{
private:
	Graphics console;
	Log Logs[5];
	Car Cars[5];
	Frog Frogger;
	int score;
	int lives;
	bool isPlaying, gameOver;

	void Init();

	// keybaord stuff
	void readKeyboard();
	void waitSpaceBar();
	
	// collision checks
	bool checkCarCollision();
	int checkLogCollision();

	// ascii screens
	void doWelcome();
	void doGameOver();
	void doWin();

public:
	Engine();
	void Run();
};


#endif // !_H_ENGINE
