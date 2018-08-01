#pragma once
#include "Std.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);

class Window
{
	friend LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
public:
	bool SetWindow(HINSTANCE, const TCHAR* = L"MywinDow");
	bool Run();
public:
	Window();
protected:
	virtual LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
	virtual bool GameInit();
	virtual bool GameRun();
	virtual bool GameRelease();
private:
	void CenterWindow();
private:
	HWND m_hWnd;
	DWORD m_dwStyle;
	RECT m_rtClient;
	RECT m_rtWindow;
};