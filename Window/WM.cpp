#include "Core.h"

class Simple : public Core
{

};


int WINAPI wWinMain(HINSTANCE hinst, HINSTANCE pinst, LPWSTR szcmdline, int cmd)
{
	Window * wd = new Simple;
	wd->setWindow(hinst);
	wd->Run();
	return 0;
}