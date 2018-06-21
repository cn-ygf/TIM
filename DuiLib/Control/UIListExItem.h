#pragma once

namespace DuiLib
{
	class CListExItem
	{
	public:
		//CPaintManagerUI *m_pManager;
		CListExItem(CPaintManagerUI& paint_manager, const wchar_t *item_xml) : paint_manager_(paint_manager), item_xml_(item_xml)
		{
			CListContainerElementUI *pListElement = static_cast<CListContainerElementUI*>(m_dlgBuilder.Create(item_xml, (UINT)0, NULL, &paint_manager_));
			SetListContainerElementUI(pListElement);
		}
		~CListExItem(){};
		CListContainerElementUI* GetListContainerElementUI() { return pListElement; }
		void SetListContainerElementUI(CListContainerElementUI* p){ pListElement = p; }
		CPaintManagerUI& paint_manager_;
		const wchar_t * item_xml_;
		virtual void UpdateData(BOOL b = TRUE){};
	private:
		int m_Id;
		int m_Index;
		CListContainerElementUI* pListElement;
		CDialogBuilder m_dlgBuilder;
	};
}
