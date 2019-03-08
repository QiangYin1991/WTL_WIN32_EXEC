// WTLClockView.cpp : implementation of the CWTLClockView class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "WTLClockView.h"

BOOL CWTLClockView::PreTranslateMessage(MSG* pMsg)
{
	pMsg;
	return FALSE;
}

LRESULT CWTLClockView::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CPaintDC dc(m_hWnd);

	CRect rc;
	CString sTime;
	GetClientRect(rc);
	if (m_bClockRunning)
	{
		sTime.Format(_T("The time is %d:%02d:%02d"), m_stLastTime.wHour, m_stLastTime.wMinute, m_stLastTime.wSecond);
	} 
	else
	{
		sTime.Format(_T("Clock stopped on %d:%02d:%02d"), m_stLastTime.wHour, m_stLastTime.wMinute, m_stLastTime.wSecond);
	}
	dc.SaveDC();
	dc.SetBkColor(RGB(255, 153, 0));
	dc.ExtTextOutW(0, 0, ETO_OPAQUE, rc, sTime, sTime.GetLength(), NULL);
	dc.RestoreDC(-1);
	return 0;
}
