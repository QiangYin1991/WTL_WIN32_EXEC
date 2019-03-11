// WTLClock2View.cpp : implementation of the CWTLClock2View class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "WTLClock2View.h"

BOOL CWTLClock2View::PreTranslateMessage(MSG* pMsg)
{
	pMsg;
	return FALSE;
}

LRESULT CWTLClock2View::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CPaintDC dc(m_hWnd);

	//TODO: Add your drawing code here
	CRect rect;
	CString sTime;
	SYSTEMTIME st;
	GetClientRect(rect);
	GetLocalTime(&st);
	sTime.Format(_T("The time is %d:%02d:%02d"), st.wHour, st.wMinute, st.wSecond);
	dc.SaveDC();
	dc.SetBkColor(RGB(255, 153, 0));
	dc.SetTextColor(RGB(0, 0, 0));
	dc.ExtTextOutW(0, 0, ETO_OPAQUE, rect, sTime, sTime.GetLength(), NULL);
	dc.RestoreDC(-1);

	return 0;
}

LRESULT CWTLClock2View::OnCreate(UINT, WPARAM, LPARAM, BOOL &)
{
	SetTimer(1, 1000);
	SetMsgHandled(false);
	return 0;
}

LRESULT CWTLClock2View::OnTimer(UINT, WPARAM, LPARAM, BOOL &)
{
	RedrawWindow();
	return 0;
}

LRESULT CWTLClock2View::OnDestroy(UINT, WPARAM, LPARAM, BOOL &)
{
	SetMsgHandled(false);
	return 0;
}
