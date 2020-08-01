

/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Object Class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/



#ifndef _H_OBJECT
#define _H_OBJECT

class Object
{
protected:
	int xPos, yPos, speed, timer, size;
	char dir;
	colour ink;

public:
	int getyPos(){ return yPos; };
	int getxPos(){ return xPos; };
	colour getColour(){ return ink; }
	int getSize(){ return size; }
	char getDir() { return dir; }

};

#endif // OBJECT_H_INCLUDED
