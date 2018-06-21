#ifndef __UIHEADICON_H__
#define __UIHEADICON_H__

#include <GdiPlus.h>
#pragma comment( lib, "GdiPlus.lib" )
using namespace Gdiplus;
class UILIB_API Gdiplus::RectF;
struct UILIB_API Gdiplus::GdiplusStartupInput;

/*
	名称：圆形头像控件（派生CButtonUI类）
*/
namespace DuiLib
{

	class UILIB_API CHeadUI : public CButtonUI
	{
	public:

		CHeadUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		void PaintBkImage(HDC hDC);

		void PaintStatusImage(HDC hDC);

		void SetBkImage(LPCTSTR pStrImage);

		void SetDefaultBkImage(LPCTSTR pStrImage){ m_sDefaultBkImage = pStrImage; }
		CDuiString GetDefaultBkImage(){ return m_sDefaultBkImage; }
		void SetAutoPenColor(bool bAuto){ m_bAutoPenColor = bAuto; }
		bool IsAutoPenColor() { return m_bAutoPenColor; }
		void SetPenColor(DWORD dwColor){ m_dwPenColor = dwColor; }
		DWORD GetPenColor(HDC hDC);
		void SetPenWidth(int nPenWidth){ m_nPenWidth = nPenWidth; }
		int GetPenWidth(){ return m_nPenWidth; }

		bool IsHeadImageExist(LPCTSTR pStrImage);

	private:

		CDuiString m_sDefaultBkImage;
		bool m_bAutoPenColor;
		DWORD m_dwPenColor;
		int m_nPenWidth;
	};
}

#endif // __UIHEADICON_H__