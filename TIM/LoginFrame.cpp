#include "stdafx.h"
#include "LoginFrame.h"
#include "MainFrame.h"

CLoginFrame *m_pThis = NULL;

CLoginFrame::CLoginFrame()
{
	m_pThis = this;
}


CLoginFrame::~CLoginFrame()
{
}


DUI_BEGIN_MESSAGE_MAP(CLoginFrame, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()


CDuiString CLoginFrame::GetSkinFolder()
{
	return _T("");
}

CDuiString CLoginFrame::GetSkinFile()
{
	return _T("loginframe.xml");
}

LPCTSTR	CLoginFrame::GetWindowClassName() const
{
	return _T("DUILoginFrame");
}

UINT CLoginFrame::GetClassStyle() const
{
	return CS_DBLCLKS; 
}

LRESULT CLoginFrame::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	return WindowImplBase::MessageHandler(uMsg, wParam, lParam, bHandled);
}

CControlUI* CLoginFrame::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void CLoginFrame::Notify(TNotifyUI& msg)
{
	CDuiString SenderName = msg.pSender->GetName();
	if (msg.sType == _T("windowinit")) 
	{
		CEditUI *pPasswordEdit = (CEditUI *)m_PaintManager.FindControl(_T("passwordedit"));
		pPasswordEdit->SetPasswordChar('*');
	}
	else if (msg.sType == _T("itemclick"))
	{
	}
	__super::Notify(msg);
}



void CLoginFrame::OnClick(TNotifyUI& msg)
{
	CDuiString pSenderName = msg.pSender->GetName();
	if (pSenderName == _T("closebtn"))
	{
		PostQuitMessage(0);
	}
	else if (pSenderName == _T("minbtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, NULL);
	}
	else if (pSenderName == _T("maxbtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, NULL);
	}
	else if (pSenderName == _T("restorebtn"))
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE, NULL);
	}
	else if (pSenderName == _T("loginbtn"))
	{
		CEditUI *pUsernameEdit = (CEditUI *)m_PaintManager.FindControl(_T("usernameedit"));
		CEditUI *pPasswordEdit = (CEditUI *)m_PaintManager.FindControl(_T("passwordedit"));
		pMainFrame = new CMainFrame;
		pMainFrame->Create(NULL, _T("TIM"), UI_WNDSTYLE_FRAME, WS_EX_STATICEDGE | WS_EX_APPWINDOW);
		pMainFrame->CenterWindow();
		pMainFrame->ShowWindow();
		this->ShowWindow(SW_HIDE);
	}
	else if (pSenderName == _T("cancelbtn......"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_bar"));
		CHorizontalLayoutUI *pTitleLayout = (CHorizontalLayoutUI *)m_PaintManager.FindControl(_T("title_layout"));
		pTabLayout->SelectItem(0);
		pTitleLayout->SetFixedHeight(pTitleLayout->GetHeight() + 45);
		this->m_bIsInput = FALSE;
		
	}
	else if (pSenderName == _T("close2btn"))
	{
		CVerticalLayoutUI *pLoginResultLayout = (CVerticalLayoutUI *)m_PaintManager.FindControl(_T("loginresult_layout"));
		pLoginResultLayout->SetVisible(false);

	}

}