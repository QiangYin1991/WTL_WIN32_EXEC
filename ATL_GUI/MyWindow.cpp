#include "MyWindow.h"
#include "AboutDlg.h"

LRESULT CMyWindow::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	HMENU hmenu = LoadMenu(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hmenu);
	return 0;
}

LRESULT CMyWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	DestroyWindow();
	return 0;
}

LRESULT CMyWindow::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT CMyWindow::OnAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL & bhandled)
{
	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}
