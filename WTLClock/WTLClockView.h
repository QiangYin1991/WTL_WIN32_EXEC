// WTLClockView.h : interface of the CWTLClockView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CWTLClockView : public CWindowImpl<CWTLClockView>
{
public:
	DECLARE_WND_CLASS(NULL)

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP_EX(CWTLClockView)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_DESTROY(OnDestroy)
		MSG_WM_ERASEBKGND(OnEraseBkgnd)
		MSG_WM_TIMER(OnTimer)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnCreate(LPCREATESTRUCT lpcs)
	{
		GetLocalTime(&m_stLastTime);
		SetTimer(1, 1000);
		SetMsgHandled(false);
		return 0;
	}
	void OnDestroy()
	{
		KillTimer(1);
		SetMsgHandled(false);
	}

	LRESULT OnEraseBkgnd(HDC hdc)
	{
		return 1;
	}

	void OnTimer(UINT uTimerID)
	{
		if (1 != uTimerID)
			SetMsgHandled(false);
		else
		{
			if (m_bClockRunning)
			{
				GetLocalTime(&m_stLastTime);
				RedrawWindow();
			}
		}
	}

	void StartClock()
	{
		m_bClockRunning = true;
		GetLocalTime(&m_stLastTime);
		RedrawWindow();
	}

	void StopClock()
	{
		m_bClockRunning = false;
		RedrawWindow();
	}
protected:
	SYSTEMTIME m_stLastTime;
	bool	   m_bClockRunning;
};
