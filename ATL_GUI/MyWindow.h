#pragma once
#include "stdafx.h"
#include "PaintBkgnd.h"

class CMyWindow : public CWindowImpl<CMyWindow, CWindow, CFrameWinTraits>
{
public:
	DECLARE_WND_CLASS(_T("My Window Class"));

	//typedef CPaintBkgnd<CMyWindow, RGB(0, 0, 255)> CPaintBkgndBase;

	BEGIN_MSG_MAP(CMyWindow)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		//COMMAND_ID_HANDLER(IDC_ABOUT, OnAbout)
	END_MSG_MAP()
	
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
	LRESULT OnAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bhandled);
};

