#pragma once
#include "Std.h"

class Timer
{
public:
	bool		Init();
	bool		Frame();
	bool		Render();
	bool		Release();
private:
	TCHAR		m_csBuffer[256];
	DWORD		m_dwBeforeTick;
	DWORD		m_FrameCount;
	float		m_fSecPerFrame;
	float		m_fGameTime;
	float		m_fTime;
};