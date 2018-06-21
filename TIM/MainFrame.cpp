#include "stdafx.h"
#include "MainFrame.h"
#include "ChatListItem.h"


CMainFrame *m_pThis = NULL;

CMainFrame::CMainFrame()
{
	m_pThis = this;
}


CMainFrame::~CMainFrame()
{
}


DUI_BEGIN_MESSAGE_MAP(CMainFrame, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()


CDuiString CMainFrame::GetSkinFolder()
{
	return _T("");
}

CDuiString CMainFrame::GetSkinFile()
{
	return _T("mainframe.xml");
}

LPCTSTR	CMainFrame::GetWindowClassName() const
{
	return _T("DUIMainFrame");
}

UINT CMainFrame::GetClassStyle() const
{
	return CS_DBLCLKS; 
}


LRESULT CMainFrame::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	return WindowImplBase::MessageHandler(uMsg, wParam, lParam, bHandled);
}

CControlUI* CMainFrame::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void CMainFrame::Notify(TNotifyUI& msg)
{
	CDuiString SenderName = msg.pSender->GetName();
	if (msg.sType == _T("windowinit")) 
	{
		InitTestData();
	}
	else if (msg.sType == _T("itemclick"))
	{
	}
	__super::Notify(msg);
}

void CMainFrame::InitTestData() 
{
	CListExUI *pChatList = (CListExUI *)(m_PaintManager.FindControl(_T("chatlist")));
	CListExUI *pFirendsList = (CListExUI *)(m_PaintManager.FindControl(_T("firendslist")));
	CListExUI *pGroupList = (CListExUI *)(m_PaintManager.FindControl(_T("grouplist")));
	CListExUI *pMultiplayerList = (CListExUI *)(m_PaintManager.FindControl(_T("multiplayerlist")));

	CChatListItem item(m_PaintManager);
	item.SetHeadPath(_T("images/251_100.gif"));
	item.SetNickName(_T("小青蛙"));
	item.SetTimeStr(_T("18:19"));
	item.SetMsg(_T("你们在干嘛."));
	item.UpdateData(TRUE);
	CChatListItem item2(m_PaintManager);
	item2.SetHeadPath(_T("images/241_100.gif"));
	item2.SetNickName(_T("小企鹅"));
	item2.SetTimeStr(_T("18:10"));
	item2.SetMsg(_T("[图片]"));
	item2.UpdateData(TRUE);
	pChatList->AddNode(&item, NULL, 0);
	pChatList->AddNode(&item2, NULL, 0);


	CChatListItem item3(m_PaintManager);
	item3.SetHeadPath(_T("images/251_100.gif"));
	item3.SetNickName(_T("小青蛙"));
	item3.SetTimeStr(_T("18:19"));
	item3.SetMsg(_T("你们在干嘛."));
	item3.UpdateData(TRUE);
	CChatListItem item4(m_PaintManager);
	item4.SetHeadPath(_T("images/241_100.gif"));
	item4.SetNickName(_T("小企鹅"));
	item4.SetTimeStr(_T("18:10"));
	item4.SetMsg(_T("[图片]"));
	item4.UpdateData(TRUE);
	pFirendsList->AddNode(&item3, NULL, 0);
	pFirendsList->AddNode(&item4, NULL, 0);


}

void CMainFrame::OnClick(TNotifyUI& msg)
{
	CDuiString pSenderName = msg.pSender->GetName();
	if (pSenderName == _T("closebtn"))
	{
		if (MessageBox(GetHWND(),TEXT("是否真的退出程序？"), TEXT("提示"), MB_YESNO | MB_ICONINFORMATION) == IDNO)
		{
			return;
		}
		
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
	else if (pSenderName == _T("chatbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_bar"));
		pTabLayout->SelectItem(0);
	}
	else if (pSenderName == _T("contactsbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_bar"));
		pTabLayout->SelectItem(1);
	}
	else if (pSenderName == _T("filebtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_bar"));
		pTabLayout->SelectItem(2);
	}
	else if (pSenderName == _T("netsetbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("set_tab"));
		pTabLayout->SelectItem(0);
		CButtonUI *pBtn = (CButtonUI *)m_PaintManager.FindControl(_T("netsetbtn"));
		pBtn->SetTextColor(0xff1790ed);
		pBtn = (CButtonUI *)m_PaintManager.FindControl(_T("aboutbtn"));
		pBtn->SetTextColor(0xff000000);

		CVerticalLayoutUI *pLayout = (CVerticalLayoutUI *)m_PaintManager.FindControl(_T("net_layout"));
		pLayout->SetVisible(true);
		pLayout = (CVerticalLayoutUI *)m_PaintManager.FindControl(_T("about_layout"));
		pLayout->SetVisible(false);
	}
	else if (pSenderName == _T("aboutbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("set_tab"));
		pTabLayout->SelectItem(1);
		CButtonUI *pBtn = (CButtonUI *)m_PaintManager.FindControl(_T("netsetbtn"));
		pBtn->SetTextColor(0xff000000);
		pBtn = (CButtonUI *)m_PaintManager.FindControl(_T("aboutbtn"));
		pBtn->SetTextColor(0xff1790ed);
		CVerticalLayoutUI *pLayout = (CVerticalLayoutUI *)m_PaintManager.FindControl(_T("net_layout"));
		pLayout->SetVisible(false);
		pLayout = (CVerticalLayoutUI *)m_PaintManager.FindControl(_T("about_layout"));
		pLayout->SetVisible(true);
	}
	else if (pSenderName == _T("logobtn"))
	{
		CPoint point(0, 0);
		ClientToScreen(this->m_hWnd, &point);
		point.y += 55;
		CMenuWnd* pMenu = CMenuWnd::CreateMenu(NULL, _T("mainmenu.xml"), point, &m_PaintManager, &m_MenuCheckInfo, eMenuAlignment_Left | eMenuAlignment_Top);
		CMenuUI* rootMenu = pMenu->GetMenuUI();
	}
	else if (pSenderName == _T("friendsbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_contacts_bar"));
		pTabLayout->SelectItem(0);
	}
	else if (pSenderName == _T("groupbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_contacts_bar"));
		pTabLayout->SelectItem(1);
	}
	else if (pSenderName == _T("mutilchatbtn"))
	{
		CTabLayoutUI *pTabLayout = (CTabLayoutUI *)m_PaintManager.FindControl(_T("tab_contacts_bar"));
		pTabLayout->SelectItem(2);
	}

}

