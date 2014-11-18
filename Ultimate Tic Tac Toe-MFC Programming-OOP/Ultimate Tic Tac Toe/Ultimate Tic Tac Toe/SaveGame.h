#pragma once
#include "afxwin.h"

class CSaveGame
{
public:
	int sboard[9][9];
	int sgame[3][3];
	int sX,sY;
	int sX_N, sY_N;
	int sfirst_move;
	int smove_player;

	CSaveGame();
	afx_msg void save();
	~CSaveGame(void);
};

