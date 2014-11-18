#pragma once
#include "afxwin.h"
#include "resource.h"
#include "string.h"
#include "SampleDialog.h"
#include "MyDialog.h"

class CMainWin :
	public CFrameWnd
{
public:
	CMainWin(void);
	~CMainWin(void);

	afx_msg void OnNew();
	afx_msg void OnOpen();
	afx_msg void OnExit();
	afx_msg void OnInstruction();
	afx_msg void OnCredit();
	afx_msg void OnRegister();

	DECLARE_MESSAGE_MAP()
};

