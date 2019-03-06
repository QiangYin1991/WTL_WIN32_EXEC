#include "stdafx.h"
#include "MyWindow.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, LPSTR szCmdLine, int nCmdShow)
{
	CMyWindow wndMain;
	MSG msg;

	if (NULL == wndMain.Create(NULL, CWindow::rcDefault, _T("My First ATL Window")))
	{
		return 1;
	}

	wndMain.ShowWindow(nCmdShow);
	wndMain.UpdateWindow();

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}