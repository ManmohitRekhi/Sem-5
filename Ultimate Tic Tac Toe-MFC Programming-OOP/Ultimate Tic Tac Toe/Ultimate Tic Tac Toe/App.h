#pragma once
#include "afxwin.h"
#include "MainWin.h"

class CApp :
	public CWinApp
{
public:
	CApp(void);
	~CApp(void);
	BOOL InitInstance(void);
};

