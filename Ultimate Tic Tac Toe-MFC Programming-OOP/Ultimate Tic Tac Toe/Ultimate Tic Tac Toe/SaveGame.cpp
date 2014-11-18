#include "SaveGame.h"


CSaveGame::CSaveGame(void)
{
	for(int i = 0; i < 9; i++)
	{
		for(int j =0; j < 9; j++)
		{
			sboard[i][j] = 0;
		}
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j =0; j < 3; j++)
		{
			sgame[i][j] = 0;
		}
	}
	sX = 0;
	sY = 0;
	sX_N = 0; 
	sY_N = 0;
	sfirst_move = 0;
	smove_player = 0;
}

afx_msg void CSaveGame::save()
{

}
