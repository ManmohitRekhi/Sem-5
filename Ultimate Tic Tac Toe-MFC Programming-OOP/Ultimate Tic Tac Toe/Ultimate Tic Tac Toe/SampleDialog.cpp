#include "SampleDialog.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int game[3][3];
int board[9][9];
int move_player = 0;
int game_started = 0;
int X,Y;
int X_N = 0, Y_N = 0;
int first_move = 0;

int get_move()
{
	//dialog box for getting input
	//and replacing X and Y
	if(X == -1 || Y == -1) return 0;
	if(board[X][Y] != -1) return 0;
	if(game[X/3][Y/3] != -1 && game[X_N][Y_N] != -1)
	{
		first_move = 0;	
		return 0;
	}
	for(int i = 0 ; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if((X_N + i == X && Y_N + j == Y) || first_move == 0)
			{
				board[X][Y] = move_player;
				first_move = 1;
				return 1;
			}
		}
	}
	return 0;
}

int check_inwin()
{
	int s = X - X%3;
	int t = Y - Y%3;
	for(int i = 0; i < 3; i++)
	{
		if(board[s+i][t+0] == move_player && board[s+i][t+1] == move_player && board[s+i][t+2] == move_player)
			return 1;
		
		if(board[s+0][t+i] == move_player && board[s+1][t+i] == move_player && board[s+2][t+i] == move_player)
			return 1;
		
	}
	if(board[s+0][t+0] == move_player && board[s+1][t+1] == move_player && board[s+2][t+2] == move_player)
		return 1;
	
	if(board[s+0][t+2] == move_player && board[s+1][t+1] == move_player && board[s+2][t+0] == move_player)
		return 1;
	
	return 0;
}

void update_board()
{
	int s = X/3;
	int t = Y/3;
	if(check_inwin())
		game[s][t] = move_player;

}

int check_win()
{
	update_board();
	for(int i = 0; i < 3; i++)
	{
		if(game[i][0] == move_player && game[i][1] == move_player && game[i][2] == move_player)
			return 1;
		
		if(game[0][i] == move_player && game[1][i] == move_player && game[2][i] == move_player)
			return 1;
		
	}
	if(game[0][0] == move_player && game[1][1] == move_player && game[2][2] == move_player)
		return 1;
	
	if(game[0][2] == move_player && game[1][1] == move_player && game[2][0] == move_player)
		return 1;
	
	return 0;
}


BOOL CSampleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	game_started = game_param;
	if(game_started == 0)
	{
		MessageBox("New Game", "Started");
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				game[i][j] = -1;
	
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				board[i][j] = -1;

		return TRUE;
	}
}


afx_msg void CSampleDialog::OnUserClick_00()
{
	X = 0;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_00);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_01()
{
	X = 0;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_01);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_02()
{
	X = 0;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_02);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
	

}
afx_msg void CSampleDialog::OnUserClick_03()
{
	
	
	
	X = 0;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_03);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_04()
{
	
	
	
	X = 0;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_04);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_05()
{
	
	
	
	X = 0;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_05);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_06()
{
	
	
	
	X = 0;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_06);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_07()
{
	
	
	
	X = 0;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_07);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_08()
{
	
	
	
	X = 0;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_08);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_10()
{
	
	
	
	X = 1;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_10);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_11()
{
	
	
	
	X = 1;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_11);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_12()
{
	
	
	
	X = 1;
	Y =	2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_12);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_13()
{
	
	
	
	X = 1;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_13);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_14()
{
	
	
	
	X = 1;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_14);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_15()
{
	
	
	
	X = 1;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_15);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_16()
{
	
	
	
	X = 1;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_16);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_17()
{
	
	
	
	X = 1;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_17);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_18()
{
	
	
	
	X = 1;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_18);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_20()
{
	
	
	
	X = 2;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_20);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_21()
{
	
	
	
	X = 2;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_21);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_22()
{
	
	
	
	X = 2;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_22);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}

}
afx_msg void CSampleDialog::OnUserClick_23()
{
	
	
	
	X = 2;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_23);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_24()
{
	
	
	
	X = 2;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_24);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_25()
{
	
	
	
	X = 2;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_25);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_26()
{
	
	
	
	X = 2;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_26);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_27()
{
	
	
	
	X = 2;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_27);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_28()
{
	
	
	
	X = 2;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_28);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_30()
{
	
	
	
	X = 3;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_30);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_31()
{
	
	
	
	X = 3;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_31);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}

afx_msg void CSampleDialog::OnUserClick_32()
{
	
	
	
	X = 3;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_32);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}

afx_msg void CSampleDialog::OnUserClick_33()
{
	
	
	
	X = 3;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_33);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_34()
{
	
	
	
	X = 3;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_34);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_35()
{
	
	
	
	X = 3;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_35);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_36()
{
	
	
	
	X = 3;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_36);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}

}
afx_msg void CSampleDialog::OnUserClick_37()
{
	
	
	
	X = 3;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_37);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_38()
{
	
	
	
	X = 3;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_38);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_40()
{
	
	
	
	X = 4;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_40);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_41()
{
	
	
	
	X = 4;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_41);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_42()
{
	
	
	
	X = 4;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_42);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_43()
{
	
	
	
	X = 4;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_43);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_44()
{
	
	
	
	X = 4;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_44);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_45()
{
	
	
	
	X = 4;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_45);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_46()
{
	
	
	
	X = 4;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_46);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_47()
{
	
	
	
	X = 4;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_47);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_48()
{
	
	
	
	X = 4;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_48);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_50()
{
	
	
	
	X = 5;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_50);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_51()
{
	
	
	
	X = 5;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_51);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_52()
{
	
	
	
	X = 5;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_52);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_53()
{
	
	
	
	X = 5;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_53);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_54()
{
	
	
	
	X = 5;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_54);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_55()
{
	
	
	
	X = 5;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_55);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_56()
{
	
	
	
	X = 5;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_56);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_57()
{
	
	
	
	X = 5;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_57);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_58()
{
	
	
	
	X = 5;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_58);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}

afx_msg void CSampleDialog::OnUserClick_60()
{
	
	
	
	X = 6;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_60);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_61()
{
	
	
	
	X = 6;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_61);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_62()
{
	
	
	
	X = 6;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_62);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_63()
{
	
	
	
	X = 6;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_63);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_64()
{
	
	
	
	X = 6;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_64);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_65()
{
	
	
	
	X = 6;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_65);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_66()
{
	
	
	
	X = 6;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_66);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_67()
{
	
	
	
	X = 6;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_67);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_68()
{
	
	
	
	X = 6;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_68);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 0;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_70()
{
	
	
	
	X = 7;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_70);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_71()
{
	
	
	
	X = 7;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_71);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}

}
afx_msg void CSampleDialog::OnUserClick_72()
{
	
	
	
	X = 7;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_72);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_73()
{
	
	
	
	X = 7;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_73);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_74()
{
	
	
	
	X = 7;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_74);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_75()
{
	
	
	
	X = 7;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_75);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_76()
{
	
	
	
	X = 7;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_76);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_77()
{
	
	
	
	X = 7;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_77);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_78()
{
	
	
	
	X = 7;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_78);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 3;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_80()
{
	
	
	
	X = 8;
	Y = 0;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_80);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_81()
{
	
	
	
	X = 8;
	Y = 1;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_81);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_82()
{
	
	
	
	X = 8;
	Y = 2;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_82);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_83()
{
	
	
	
	X = 8;
	Y = 3;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_83);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_84()
{
	
	
	
	X = 8;
	Y = 4;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_84);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_85()
{
	
	
	
	X = 8;
	Y = 5;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_85);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_86()
{
	
	
	
	X = 8;
	Y = 6;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_86);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 0;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_87()
{
	
	
	
	X = 8;
	Y = 7;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_87);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 3;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}
afx_msg void CSampleDialog::OnUserClick_88()
{
	
	
	
	X = 8;
	Y = 8;
	if(get_move())
	{
		CButton *Button1 = (CButton *) GetDlgItem(IDC_BUTTON_88);
		if(move_player == 0)
			Button1->SetWindowTextA("X");
		else 
			Button1->SetWindowTextA("O");

		X_N = 6;
		Y_N = 6;
		if(check_win())
		{
			if(move_player)
				MessageBox("PLAYER 2 WINS", "CONGRATULATIONS");
			else
				MessageBox("PLAYER 1 WINS", "CONGRATULATIONS");
			EndDialog(0);
		}
		move_player = 1 - move_player;
	}
}


BEGIN_MESSAGE_MAP(CSampleDialog, CDialog)
	ON_COMMAND(IDC_BUTTON_00, OnUserClick_00)
	ON_COMMAND(IDC_BUTTON_01, OnUserClick_01)
	ON_COMMAND(IDC_BUTTON_02, OnUserClick_02)
	ON_COMMAND(IDC_BUTTON_03, OnUserClick_03)
	ON_COMMAND(IDC_BUTTON_04, OnUserClick_04)
	ON_COMMAND(IDC_BUTTON_05, OnUserClick_05)
	ON_COMMAND(IDC_BUTTON_06, OnUserClick_06)
	ON_COMMAND(IDC_BUTTON_07, OnUserClick_07)
	ON_COMMAND(IDC_BUTTON_08, OnUserClick_08)
	ON_COMMAND(IDC_BUTTON_10, OnUserClick_10)
	ON_COMMAND(IDC_BUTTON_11, OnUserClick_11)
	ON_COMMAND(IDC_BUTTON_12, OnUserClick_12)
	ON_COMMAND(IDC_BUTTON_13, OnUserClick_13)
	ON_COMMAND(IDC_BUTTON_14, OnUserClick_14)
	ON_COMMAND(IDC_BUTTON_15, OnUserClick_15)
	ON_COMMAND(IDC_BUTTON_16, OnUserClick_16)
	ON_COMMAND(IDC_BUTTON_17, OnUserClick_17)
	ON_COMMAND(IDC_BUTTON_18, OnUserClick_18)
	ON_COMMAND(IDC_BUTTON_20, OnUserClick_20)
	ON_COMMAND(IDC_BUTTON_21, OnUserClick_21)
	ON_COMMAND(IDC_BUTTON_22, OnUserClick_22)
	ON_COMMAND(IDC_BUTTON_23, OnUserClick_23)
	ON_COMMAND(IDC_BUTTON_24, OnUserClick_24)
	ON_COMMAND(IDC_BUTTON_25, OnUserClick_25)
	ON_COMMAND(IDC_BUTTON_26, OnUserClick_26)
	ON_COMMAND(IDC_BUTTON_27, OnUserClick_27)
	ON_COMMAND(IDC_BUTTON_28, OnUserClick_28)
	ON_COMMAND(IDC_BUTTON_30, OnUserClick_30)
	ON_COMMAND(IDC_BUTTON_31, OnUserClick_31)
	ON_COMMAND(IDC_BUTTON_32, OnUserClick_32)
	ON_COMMAND(IDC_BUTTON_33, OnUserClick_33)
	ON_COMMAND(IDC_BUTTON_34, OnUserClick_34)
	ON_COMMAND(IDC_BUTTON_35, OnUserClick_35)
	ON_COMMAND(IDC_BUTTON_36, OnUserClick_36)
	ON_COMMAND(IDC_BUTTON_37, OnUserClick_37)
	ON_COMMAND(IDC_BUTTON_38, OnUserClick_38)
	ON_COMMAND(IDC_BUTTON_40, OnUserClick_40)
	ON_COMMAND(IDC_BUTTON_41, OnUserClick_41)
	ON_COMMAND(IDC_BUTTON_42, OnUserClick_42)
	ON_COMMAND(IDC_BUTTON_43, OnUserClick_43)
	ON_COMMAND(IDC_BUTTON_44, OnUserClick_44)
	ON_COMMAND(IDC_BUTTON_45, OnUserClick_45)
	ON_COMMAND(IDC_BUTTON_46, OnUserClick_46)
	ON_COMMAND(IDC_BUTTON_47, OnUserClick_47)
	ON_COMMAND(IDC_BUTTON_48, OnUserClick_48)
	ON_COMMAND(IDC_BUTTON_50, OnUserClick_50)
	ON_COMMAND(IDC_BUTTON_51, OnUserClick_51)
	ON_COMMAND(IDC_BUTTON_52, OnUserClick_52)
	ON_COMMAND(IDC_BUTTON_53, OnUserClick_53)
	ON_COMMAND(IDC_BUTTON_54, OnUserClick_54)
	ON_COMMAND(IDC_BUTTON_55, OnUserClick_55)
	ON_COMMAND(IDC_BUTTON_56, OnUserClick_56)
	ON_COMMAND(IDC_BUTTON_57, OnUserClick_57)
	ON_COMMAND(IDC_BUTTON_58, OnUserClick_58)
	ON_COMMAND(IDC_BUTTON_60, OnUserClick_60)
	ON_COMMAND(IDC_BUTTON_61, OnUserClick_61)
	ON_COMMAND(IDC_BUTTON_62, OnUserClick_62)
	ON_COMMAND(IDC_BUTTON_63, OnUserClick_63)
	ON_COMMAND(IDC_BUTTON_64, OnUserClick_64)
	ON_COMMAND(IDC_BUTTON_65, OnUserClick_65)
	ON_COMMAND(IDC_BUTTON_66, OnUserClick_66)
	ON_COMMAND(IDC_BUTTON_67, OnUserClick_67)
	ON_COMMAND(IDC_BUTTON_68, OnUserClick_68)
	ON_COMMAND(IDC_BUTTON_70, OnUserClick_70)
	ON_COMMAND(IDC_BUTTON_71, OnUserClick_71)
	ON_COMMAND(IDC_BUTTON_72, OnUserClick_72)
	ON_COMMAND(IDC_BUTTON_73, OnUserClick_73)
	ON_COMMAND(IDC_BUTTON_74, OnUserClick_74)
	ON_COMMAND(IDC_BUTTON_75, OnUserClick_75)
	ON_COMMAND(IDC_BUTTON_76, OnUserClick_76)
	ON_COMMAND(IDC_BUTTON_77, OnUserClick_77)
	ON_COMMAND(IDC_BUTTON_78, OnUserClick_78)
	ON_COMMAND(IDC_BUTTON_80, OnUserClick_80)
	ON_COMMAND(IDC_BUTTON_81, OnUserClick_81)
	ON_COMMAND(IDC_BUTTON_82, OnUserClick_82)
	ON_COMMAND(IDC_BUTTON_83, OnUserClick_83)
	ON_COMMAND(IDC_BUTTON_84, OnUserClick_84)
	ON_COMMAND(IDC_BUTTON_85, OnUserClick_85)
	ON_COMMAND(IDC_BUTTON_86, OnUserClick_86)
	ON_COMMAND(IDC_BUTTON_87, OnUserClick_87)
	ON_COMMAND(IDC_BUTTON_88, OnUserClick_88)
END_MESSAGE_MAP()