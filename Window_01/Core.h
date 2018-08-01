#pragma once
#include "Timer.h"
#include "Window.h"
class Core : public Window
{
public:
	bool		GameInit();
	bool		GameRun();
	bool		GameRelease();
private:
	Timer m_Timer;
};