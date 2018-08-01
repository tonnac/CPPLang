#include "Timer.h"

bool Timer::Init()
{
	m_dwBeforeTick = timeGetTime();
	return true;
}
bool Timer::Frame()
{
	time_t clock;
	DWORD dwCurrentTick = timeGetTime();
	DWORD dwElapsedTick = dwCurrentTick - m_dwBeforeTick;
	m_fSecPerFrame = dwElapsedTick / 1000.0f;
	m_fGameTimer += m_fSecPerFrame;
	clock = m_fGameTimer;
	tm lt;
	localtime_s(&lt, &clock);
	m_fTimer += m_fSecPerFrame;
	if (m_fTimer >= 1.0)
	{
		m_fTimer -= 1.0;
		m_dwFPS = m_dwFrameCount;
		m_dwFrameCount = 0;
		_stprintf_s(m_csBuffer, L"Ω√:%d, ∫–:%d, √ :%d FPS:%d, TIME:%5.4f, SPF:%5.4f", lt.tm_hour,lt.tm_min,lt.tm_sec,m_dwFPS, m_fGameTimer, m_fSecPerFrame);
	//	OutputDebugString(m_csBuffer);
	}
	m_dwFrameCount++;
	m_dwBeforeTick = dwCurrentTick;
	return true;
}
bool Timer::Render()
{
	HDC hdc = GetDC(g_hWnd);
	TextOut(hdc, 0, 0, m_csBuffer, wcslen(m_csBuffer));

	ReleaseDC(g_hWnd, hdc);
	return true;
}
bool Timer::Release()
{
	return true;
}

Timer::Timer()
{
	float m_fSecPerFrame = 0.0f;
	float m_fTimer = 0.0f;
	float m_fGameTimer = 0.0f;
	DWORD m_dwBeforeTick = 0;
	DWORD m_dwFPS = 0;
	DWORD m_dwFrameCount = 0;
}


Timer::~Timer()
{
}
