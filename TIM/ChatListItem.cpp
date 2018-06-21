#include "stdafx.h"
#include "ChatListItem.h"


CChatListItem::CChatListItem(CPaintManagerUI& paint_manager) :CListExItem(paint_manager, _T("chatlistitem.xml"))
{
}


CChatListItem::~CChatListItem()
{
}

void CChatListItem::UpdateData(BOOL b)
{
	CListContainerElementUI *pListElement = GetListContainerElementUI();
	CHeadUI *pHead = (CHeadUI *)paint_manager_.FindSubControlByName(pListElement, _T("headbtn"));
	CLabelUI *pNickName = (CLabelUI *)paint_manager_.FindSubControlByName(pListElement, _T("nicktext"));
	CLabelUI *pTimeStr = (CLabelUI *)paint_manager_.FindSubControlByName(pListElement, _T("timetext"));
	CLabelUI *pMsg = (CLabelUI *)paint_manager_.FindSubControlByName(pListElement, _T("msgtext"));
	if (b)
	{
		pHead->SetBkImage(m_HeadPath);
		pNickName->SetText(m_NickName);
		pTimeStr->SetText(m_TimeStr);
		pMsg->SetText(m_Msg);
	}
	else
	{
		m_HeadPath = pHead->GetBkImage();
		m_NickName = pNickName->GetText();
		m_TimeStr = pTimeStr->GetText();
		m_Msg = pMsg->GetText();
	}
}

void CChatListItem::SetHeadPath(CDuiString str)
{
	this->m_HeadPath = str;
}
void CChatListItem::SetNickName(CDuiString str)
{
	this->m_NickName = str;
}
void CChatListItem::SetTimeStr(CDuiString str)
{
	this->m_TimeStr = str;
}
void CChatListItem::SetMsg(CDuiString str)
{
	this->m_Msg = str;
}
CDuiString CChatListItem::GetHeadPath()
{
	return m_HeadPath;
}
CDuiString CChatListItem::GetNickName()
{
	return m_NickName;
}
CDuiString CChatListItem::GetTimeStr()
{
	return m_TimeStr;
}
CDuiString CChatListItem::GetMsg()
{
	return m_Msg;
}