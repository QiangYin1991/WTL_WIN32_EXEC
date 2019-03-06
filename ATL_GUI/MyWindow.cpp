#include "MyWindow.h"

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
	MessageBox(_T("Sample ATL window"), _T("About MyWindow"));
	return 0;
}
