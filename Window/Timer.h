#pragma once
#include "Window.h"
#include <ctime>
class Timer
{
public:
	bool	Init();
	bool	Frame();
	bool	Render();
	bool	Release();
public:
	Timer();
	virtual ~Timer();
private:
	float m_fSecPerFrame;
	float m_fTimer;
	float m_fGameTimer;
	DWORD m_dwBeforeTick;
	DWORD m_dwFPS;
	DWORD m_dwFrameCount;
	TCHAR m_csBuffer[256];
};

