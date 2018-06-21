#pragma once

#include "UIListExNode.h"
#include "UIList.h"

namespace DuiLib
{
	class CListExItem;

	class UILIB_API CListExUI : public CListUI
	{
	public:
		enum { SCROLL_TIMERID = 10 };
		CListExUI(/*CPaintManagerUI& paint_manager*/);
		~CListExUI();

		Node* AddNode(CListExItem *item, Node* parent, int insertIndex = -1);
		CListExItem* GetMyListItemAt(int index);
		void DoEvent(TEventUI& event);
		void RemoveAll();
		bool RemoveNode(Node* node);
		Node* GetRoot();
		//CPaintManagerUI& paint_manager_;
	private:

		LONG	delay_deltaY_;			//与滚动条滑动速度有关
		DWORD	delay_number_;
		DWORD	delay_left_;
		Node*	root_node_;				//父节点
		bool OnButtonEvent(void* param);

		int m_currnet;
	};

}