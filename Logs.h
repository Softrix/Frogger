

/*


		$file:						Frogger Remake ( For the console)
		$purpose:					Logs Class
		$author:					Kyle Lanmon / Michael Boyle (Softrix)


*/



#ifndef _H_LOGS
#define _H_LOGS

#include "Graphics.h"
#include "Object.h"

class Log : public Object
{
private:
	Graphics console;
	void drawLog();
	void clearLog();

public:
	Log();
	void setLog(int, int, int, int, char, colour);
	void updateLog();
};

#endif

