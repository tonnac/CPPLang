#pragma once
#include <windows.h>
#include <tchar.h>

#define GAMESTART int WINAPI wWinMain(HINSTANCE hinst, HINSTANCE preinst, LPWSTR szCmdline, int cmd) {
#define GAMERELEASE }
#define GAMERUN(w) GAMESTART \
				   Simple wd;   \
				   wd.SetWindow(hinst,L#w); \
				   wd.Run(); \
				   return 0; \
				   GAMERELEASE

extern HWND g_hWnd;