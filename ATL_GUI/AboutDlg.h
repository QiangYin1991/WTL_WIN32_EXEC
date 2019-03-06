#pragma once
#include "stdafx.h"
#include "resource.h"

class CAboutDlg : public CDialogImpl<CAboutDlg>
{
public:
	enum { IDD = IDD_ABOUT };
public:
	CAboutDlg();
	~CAboutDlg();

	BEGIN_MSG_MAP(CAboutDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		COMMAND_ID_HANDLER(IDOK, OnOKCancel)
		COMMAND_ID_HANDLER(IDCANCEL, OnOKCancel)
	END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnOKCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled);
};

