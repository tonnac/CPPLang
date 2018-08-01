#include "Window.h"

Window * g_pWindow = nullptr;
HWND g_hWnd;

bool Window::SetWindow(HINSTANCE hinst, const TCHAR* pTitleName)
{
	WNDCLASSEX wd;
	ZeroMemory(&wd, sizeof(WNDCLASSEX));
	wd.cbSize = sizeof(WNDCLASSEX);
	wd.style = CS_HREDRAW | CS_VREDRAW;
	wd.lpfnWndProc = WndProc;
	wd.hInstance = hinst;
	wd.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
	wd.hCursor = LoadCursor(nullptr, IDC_PERSON);
	wd.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wd.lpszMenuName = pTitleName;
	wd.lpszClassName = L"Class";
	wd.hIconSm = LoadIcon(nullptr, IDI_ERROR);

	if (!RegisterClassEx(&wd))
	{
		return false;
	}
	m_hWnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		wd.lpszClassName,
		wd.lpszMenuName,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		1024,
		768,
		nullptr,
		nullptr,
		hinst,
		nullptr);
	if (m_hWnd == nullptr)
	{
		return false;
	}
	::g_hWnd = m_hWnd;
	GetClientRect(m_hWnd, &m_rtClient);
	GetWindowRect(m_hWnd, &m_rtWindow);

	CenterWindow();

	ShowWindow(m_hWnd, SW_SHOW);
	return true;
}
bool Window::Run()
{
	if (!GameInit()) return false;
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			Sleep(1);
			GameRun();
		}
	}
	return GameRelease();
}

Window::Window() : m_dwStyle(WS_OVERLAPPEDWINDOW)
{
	::g_pWindow = this;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	LRESULT ret;
	if (ret = ::g_pWindow->MsgProc(hWnd, msg, wparam, lparam))
	{
		return ret;
	}
	return DefWindowProc(hWnd, msg, wparam, lparam);
}
LRESULT CALLBACK Window::MsgProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_MBUTTONDOWN:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return 0;
}

bool Window::GameInit()
{
	 return true;
}
bool Window::GameRun()
{
	return true;
}
bool Window::GameRelease()
{
	return true;
}

void Window::CenterWindow()
{
	int iScreenWidth = GetSystemMetrics(SM_CXFULLSCREEN);
	int iScreenHeight = GetSystemMetrics(SM_CYFULLSCREEN);
	int x = ((iScreenWidth - (m_rtWindow.right - m_rtWindow.left)) / 2);
	int y = ((iScreenHeight - (m_rtWindow.bottom - m_rtWindow.top)) / 2);
	MoveWindow(m_hWnd, x, y, m_rtWindow.right - m_rtWindow.left, m_rtWindow.bottom - m_rtWindow.top, true);
}