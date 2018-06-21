#pragma once

class CChatListItem :
	public CListExItem
{
public:
	CChatListItem(CPaintManagerUI& paint_manager);
	~CChatListItem();
private:
	CDuiString m_HeadPath;
	CDuiString m_NickName;
	CDuiString m_TimeStr;
	CDuiString m_Msg;
public:
	void SetHeadPath(CDuiString str);
	void SetNickName(CDuiString str);
	void SetTimeStr(CDuiString str);
	void SetMsg(CDuiString str);
	CDuiString GetHeadPath();
	CDuiString GetNickName();
	CDuiString GetTimeStr();
	CDuiString GetMsg();
	virtual void UpdateData(BOOL b = TRUE);
};

