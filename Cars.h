
/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Cars Class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/


#ifndef _H_CARS
#define _H_CARS

#include "Graphics.h"
#include "Object.h"

class Car : public Object
{
private:
	Graphics console;
	void drawCar();
	void clearCar();
public:
	Car();
	void setCar(int, int, int, int, char, colour);
	void updateCar();

};

#endif
