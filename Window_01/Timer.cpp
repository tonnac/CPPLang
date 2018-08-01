#include "Timer.h"
bool Timer::Init()
{
	m_dwBeforeTick = timeGetTime();
	return true;
}
bool Timer::Frame()
{
	DWORD dwCurrentTick = timeGetTime();
	DWORD dwElapsedTick = dwCurrentTick - m_dwBeforeTick;
	m_fSecPerFrame = dwElapsedTick / 1000.0f;
	m_fGameTime += m_fSecPerFrame;
	m_fTime += m_fSecPerFrame;

	if (m_fTime >= 1.0f)
	{
		m_fTime -= 1;
		_stprintf_s(m_csBuffer, L"\nFPS:%d \t Time:%3.3f \t SPF:%5.3f", m_FrameCount, m_fGameTime, m_fSecPerFrame);
//		OutputDebugString(m_csBuffer);
		m_FrameCount = 0;
	}
	m_FrameCount++;
	m_dwBeforeTick = dwCurrentTick;
	return true;
}
bool Timer::Render()
{
	HDC hdc = GetDC(::g_hWnd);
	TextOut(hdc, 0, 0, m_csBuffer, wcslen(m_csBuffer));
	ReleaseDC(::g_hWnd, hdc);
	return true;
}
bool Timer::Release()
{
	return true;
}