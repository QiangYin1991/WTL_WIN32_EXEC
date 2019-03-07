#include "stdafx.h"
#include "MyWindow.h"

CAppModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_Module.Init(NULL, hInstance);

	MyFirstWTLWindow::CMyWindow wndMain;
	MSG msg;

	if (NULL == wndMain.CreateEx())
		return 1;

	wndMain.ShowWindow(nCmdShow);
	wndMain.UpdateWindow();

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	_Module.Term();
	return msg.wParam;
}