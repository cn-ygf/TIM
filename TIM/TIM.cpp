// TIM.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "TIM.h"
#include "LoginFrame.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	::CoInitialize(NULL);
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("Resource"));
	CLoginFrame loginFrame;
	loginFrame.Create(NULL, _T("TIMLogin"), UI_WNDSTYLE_DIALOG, WS_EX_STATICEDGE | WS_EX_APPWINDOW);
	loginFrame.CenterWindow();
	loginFrame.ShowModal();

	::CoUninitialize();
	return 0;
}
