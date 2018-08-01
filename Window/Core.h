#pragma once
#include "Window.h"
#include "Timer.h"
class Core : public Window
{
public:
	bool		GameInit();
	bool		GameRun();
	bool		GameRelease();
public:
	Core();
	virtual ~Core();
private:
	Timer m_Timer;
};

