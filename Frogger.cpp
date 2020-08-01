
/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Game Engine Class
		$author:					Michael Boyle (Softrix)


*/


#include "Frogger.h"

// comment the below #define to remove
// frog position debug info.
#define SHOW_FROG_DEBUG_INFO

Engine::Engine()
{
	//Init();
}

// initialise for new game
void Engine::Init()
{
	// reset score and flags
	score = 0;
	lives = 3;
	isPlaying = true;
	gameOver = false;

	//size and colour scheme
	console.setConsoleSize(60, 85);

	// parameters for setLog and setCar 
	// are x, y, delay, len, dir, colour

	// letup logs
	Logs[0].setLog(0, 3, 1, 10, 'R', grey);
	Logs[1].setLog(0, 8, 2, 10, 'L', darkred);
	Logs[2].setLog(0, 13, 2, 10, 'R', lightgrey);
	Logs[3].setLog(0, 18, 1, 10, 'L', black);
	Logs[4].setLog(30, 23, 1, 10, 'R', darkred);
	
	// setup cars
	Cars[0].setCar(10, 29, 1, 7, 'R', red);
	Cars[1].setCar(30, 34, 1, 10, 'L', blue);
	Cars[2].setCar(60, 39, 1, 6, 'R', green);
	Cars[3].setCar(80, 44, 1, 12, 'L', yellow);
	Cars[4].setCar(60, 49, 1, 7, 'R', purple);

	// welcome
	doWelcome();

}

// main game loop
void Engine::Run()
{	
	do
	{
		// initialise 
		Init();
		console.drawWorld();

		do
		{
			Sleep(10);  // be friendly to the cpu

			// scan the keyboard and take care of
			// our frog player movement.
			readKeyboard();
			
			// draw frog
//			Frogger.drawFrog();

			// update logs
			for (int i = 0; i < 5; i++) {
				Logs[i].updateLog();
				Cars[i].updateCar();
			}

			// draw frog
			Frogger.drawFrog();
			
			// collided with log?
			if (checkLogCollision() > -1) {
				// I am on a log, what direction am i going?				
				Frogger.logMoveFrog(Logs[checkLogCollision()].getDir());
			}
			else
			{
				// im not on a log, but am i in that area?
				if (Frogger.getyPos() <= 23) {
					lives--;
					Frogger.resetPosition();  // reset back to start
				}
			}

			// have we collided with the cars?
			if (checkCarCollision()) {
				lives--;
				Frogger.resetPosition();  // reset back to start
			}
			
			// check if we have zero lives
			if (lives == 0)
				gameOver = true;

			// display lives/score.
			console.setColour(white);
			console.move(3, 56);
			std::cout << "Score: " << score;
			console.move(15, 56);
			std::cout << "Lives: " << lives;

#ifdef SHOW_FROG_DEBUG_INFO
			// DEBUG INFO
			console.setColour(red);
			console.move(44, 56);
			std::cout << "(Frog Debug Info)  xPos: " << Frogger.getxPos() << "   ";
			console.move(74, 56);
			std::cout << "yPos: " << Frogger.getyPos() << "   ";
#endif

		} while (!gameOver);

		// show game over screen.
		doGameOver();

	} while (isPlaying);

	// isPlaying is there should we want to ask player if he
	// or she wants to play again, at the moment its merely
	// a loop for endless play on each game over.  Mik

}

// read keypress
void Engine::readKeyboard()
{
	char ch;
	// have we detected a keypress?
	if (_kbhit())
	{
		ch = _getch();
		Frogger.plrMoveFrog(ch);
	}
}

// wait for space bar
void Engine::waitSpaceBar()
{
	char ch;
	//wait for spacebar to be pressed
	do { ch = _getch(); } while (ch != ' ');
	system("cls");
}

// do welcome screen.
void Engine::doWelcome()
{
	int i = 0;
	console.setColour(green);
	while (startscreen[i] != 0) { std::cout << startscreen[i]; i++; }
	waitSpaceBar();
}

// do game over screen
void Engine::doGameOver()
{
	int i = 0;
	system("cls");
	console.setColour(red);
	while (loseScreen[i] != 0) { std::cout << loseScreen[i]; i++; }
	waitSpaceBar();
}

void Engine::doWin()
{
	int i = 0;
	system("cls");
	console.setColour(green);
	while (winScreen[i] != 0) { std::cout << winScreen[i]; i++; }
	waitSpaceBar();
}

// Check collision with frog and cars.
bool Engine::checkCarCollision()
{
	for (int car = 0; car < 5; car++)
		for (int size = 0; size < Cars[car].getSize(); size++)
			if(Frogger.getxPos() == Cars[car].getxPos() + size && Frogger.getyPos() == Cars[car].getyPos())
				return true;
	return false;
}

int Engine::checkLogCollision()
{
	for (int log = 0; log < 5; log++)
		for (int size = 0; size < Logs[log].getSize(); size++)
			if (Frogger.getxPos() == Logs[log].getxPos() + size && Frogger.getyPos() == Logs[log].getyPos())
				return log;
	return -1;
}