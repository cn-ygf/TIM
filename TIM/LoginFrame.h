#pragma once

class CMainFrame;

class CLoginFrame:
	public WindowImplBase
{
private:
	BOOL m_bIsInput = FALSE;
public:
	CLoginFrame();
	~CLoginFrame();
	virtual LPCTSTR    GetWindowClassName() const;
	virtual UINT GetClassStyle() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP()
	virtual void OnClick(TNotifyUI& msg);
	CMainFrame *pMainFrame;
};

