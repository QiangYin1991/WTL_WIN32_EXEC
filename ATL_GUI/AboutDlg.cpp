#include "AboutDlg.h"



CAboutDlg::CAboutDlg()
{
}


CAboutDlg::~CAboutDlg()
{
}

LRESULT CAboutDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	CenterWindow();
	return TRUE;
}

LRESULT CAboutDlg::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	EndDialog(IDCANCEL);
	return 0;
}

LRESULT CAboutDlg::OnOKCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL & bHandled)
{
	EndDialog(wID);
	return 0;
}
