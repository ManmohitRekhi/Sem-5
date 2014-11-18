#include "MainWin.h"


CMainWin::CMainWin(void)
{
	Create(NULL,"ULTIMATE TIC-TAC-TOE", WS_OVERLAPPEDWINDOW,rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
	if(!LoadAccelTable(MAKEINTRESOURCE(IDR_ACCELERATOR1)))
	{
		MessageBox("SHORTCUT KEYS DISABLED", "FEATURE MISSING");
	}
}


CMainWin::~CMainWin(void)
{
}


afx_msg void CMainWin::OnNew()
{
	CSampleDialog diagOB(MAKEINTRESOURCE(IDD_DIALOG1), this, 0);

	diagOB.DoModal();
}

afx_msg void CMainWin::OnOpen()
{
	CSampleDialog diagOB(MAKEINTRESOURCE(IDD_DIALOG1), this, 1);

	diagOB.DoModal();
}

afx_msg void CMainWin::OnExit()
{
	int response;
	response = MessageBox("Quit the Game?", "Exit", MB_YESNO);
	if(response == IDYES)
	{
		SendMessage(WM_CLOSE);
	}
}

afx_msg void CMainWin::OnCredit()
{
	MessageBox("Game Master Manmohit Rekhi \nGame Master Shubham Pachori", "THIS GAME IS BROUGHT TO YOU BY:-");
	MessageBox("Game Professor Vipul Chudasma \nOOP SPECIAL DIVISION", "UNDER THE GUIDANCE OF:");
}

afx_msg void CMainWin::OnInstruction()
{
	ShellExecute(0, 0, "file:///C:/Users/Dell/Documents/Visual%20Studio%202012/Projects/Ultimate%20Tic%20Tac%20Toe/instructions.html", 0, 0 , SW_MAXIMIZE );
}

afx_msg void CMainWin::OnRegister()
{
	CMyDialog diagOB(MAKEINTRESOURCE(IDD_REGFORM), this);

	diagOB.DoModal();
}

BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_COMMAND(ID_FILE_NEW, OnNew)
	ON_COMMAND(ID_FILE_OPEN, OnOpen)
	ON_COMMAND(ID_FILE_EXIT, OnExit)
	ON_COMMAND(ID_CREDITS, OnCredit)
	ON_COMMAND(ID_INSTRUCTIONS, OnInstruction)
	ON_COMMAND(ID_REGISTER, OnRegister)
END_MESSAGE_MAP()