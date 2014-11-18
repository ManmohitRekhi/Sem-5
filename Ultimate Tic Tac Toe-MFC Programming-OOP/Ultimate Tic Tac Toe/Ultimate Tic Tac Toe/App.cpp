#include "App.h"


CApp::CApp(void)
{
}


CApp::~CApp(void)
{
}


BOOL CApp::InitInstance(void)
{
	m_pMainWnd = new CMainWin();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

CApp App;