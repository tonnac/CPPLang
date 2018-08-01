#pragma once
#include <windows.h>
#include <tchar.h>
#include <cassert>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);

extern HWND g_hWnd;

class Window
{
	friend LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
public:
	bool setWindow(HINSTANCE hinst, const TCHAR* pTitleName = L"Win");
	bool Run();
protected:
	virtual LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
	virtual bool GameInit();
	virtual bool GameRun();
	virtual bool GameRelease();
private:
	void CenterWindow();
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	RECT m_rtClient;
	RECT m_rtWindow;
	DWORD m_dwStyle;
public:
	Window();
};