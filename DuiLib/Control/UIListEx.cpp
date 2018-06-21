#include "stdafx.h"
#include "UIListEx.h"
#include "UIListExItem.h"

namespace DuiLib
{


	CListExUI::CListExUI(/*CPaintManagerUI& paint_manager*/)
	:/*paint_manager_(paint_manager),*/
	delay_deltaY_(0),
	delay_number_(0), 
	delay_left_(0)
	{
		root_node_ = new Node;
		root_node_->data().list_elment_ = NULL;
	}


	CListExUI::~CListExUI()
	{
		RemoveAll();
		if (root_node_)
			delete root_node_;
		root_node_ = NULL;
	}

	static bool OnLogoButtonEvent(void* event)
	{
		if (((TEventUI*)event)->Type == UIEVENT_BUTTONDOWN)
		{
			CControlUI* pButton = ((TEventUI*)event)->pSender;
			if (pButton != NULL)
			{
				CListContainerElementUI* pListElement = (CListContainerElementUI*)(pButton->GetTag());
				if (pListElement != NULL) pListElement->DoEvent(*(TEventUI*)event);
			}
		}
		return true;
	}

	CListExItem* CListExUI::GetMyListItemAt(int index)
	{
		return root_node_->child(index)->data().list_item_;
	}


	Node* CListExUI::AddNode(CListExItem *item, Node* parent, int insertIndex)
	{
		if (parent == NULL)
			parent = root_node_;

		CListContainerElementUI *pListElement = item->GetListContainerElementUI();

		Node* node = new Node;
		node->data().list_elment_ = item->GetListContainerElementUI();
		node->data().list_item_ = item;

		pListElement->SetTag((UINT_PTR)node);
		pListElement->SetFixedHeight(60);
		
		int index = 0;
		if (parent->has_children())
		{
			Node* prev = parent->get_last_child();
			index = prev->data().list_elment_->GetIndex() + 1;
		}
		else
		{
			if (parent == root_node_)
				index = 0;
			else
				index = parent->data().list_elment_->GetIndex() + 1;
		}
		bool ret = CListUI::AddAt(pListElement, insertIndex == -1 ? index : insertIndex);
		if (ret == false)
		{
			delete pListElement;
			delete node;
			node = NULL;
		}
		parent->add_child(node);
		return node;
	}

	void CListExUI::DoEvent(TEventUI& event)
	{
		if (event.Type == UIEVENT_MOUSEENTER)
		{

		}
		if (event.Type == UIEVENT_TIMER && event.wParam == SCROLL_TIMERID)
		{
			if (delay_left_ > 0)
			{
				--delay_left_;
				SIZE sz = GetScrollPos();
				LONG lDeltaY = (LONG)(CalculateDelay((double)delay_left_ / delay_number_) * delay_deltaY_);
				if ((lDeltaY > 0 && sz.cy != 0) || (lDeltaY < 0 && sz.cy != GetScrollRange().cy))
				{
					sz.cy -= lDeltaY;
					SetScrollPos(sz);
					return;
				}
			}
			delay_deltaY_ = 0;
			delay_number_ = 0;
			delay_left_ = 0;
			m_pManager->KillTimer(this, SCROLL_TIMERID);
			return;
		}
		if (event.Type == UIEVENT_SCROLLWHEEL)
		{
			LONG lDeltaY = 0;
			if (delay_number_ > 0)
				lDeltaY = (LONG)(CalculateDelay((double)delay_left_ / delay_number_) * delay_deltaY_);
			switch (LOWORD(event.wParam))
			{
			case SB_LINEUP:
				if (delay_deltaY_ >= 0)
					delay_deltaY_ = lDeltaY + 7;
				else
					delay_deltaY_ = lDeltaY + 11;
				break;
			case SB_LINEDOWN:
				if (delay_deltaY_ <= 0)
					delay_deltaY_ = lDeltaY - 7;
				else
					delay_deltaY_ = lDeltaY - 11;
				break;
			}
			if
				(delay_deltaY_ > 100) delay_deltaY_ = 100;
			else if
				(delay_deltaY_ < -100) delay_deltaY_ = -100;

			delay_number_ = (DWORD)sqrt((double)abs(delay_deltaY_)) * 5;
			delay_left_ = delay_number_;
			m_pManager->SetTimer(this, SCROLL_TIMERID, 20U);
			return;
		}
		if (event.Type == UIEVENT_CONTEXTMENU)
		{
			//m_pManager->SendNotify(this, DUI_MSGTYPE_MYLIST_MENU, (WPARAM)GetCurSel(), event.lParam);
		}


		CListUI::DoEvent(event);
	}

	void CListExUI::RemoveAll()
	{
		CListUI::RemoveAll();
		for (int i = 0; i<root_node_->num_children();)
		{
			Node* child = root_node_->child(i);
			RemoveNode(child);
		}
		delete root_node_;

		root_node_ = new Node;
		root_node_->data().list_elment_ = NULL;
	}

	bool CListExUI::RemoveNode(Node* node)
	{
		if (!node || node == root_node_)
			return false;
		for (int i = 0; i<node->num_children(); ++i)
		{
			Node* child = node->child(i);
			RemoveNode(child);
		}

		CListUI::Remove(node->data().list_elment_);

		node->parent()->remove_child(node);
		delete node;
		node = NULL;
		return true;
	}

	Node* CListExUI::GetRoot()
	{
		return root_node_;
	}

	bool CListExUI::OnButtonEvent(void* param)
	{
		TEventUI* pEvent = (TEventUI*)param;
		if (pEvent->Type == UIEVENT_SETCURSOR) {
			return false;
		}
		return true;
	}
}