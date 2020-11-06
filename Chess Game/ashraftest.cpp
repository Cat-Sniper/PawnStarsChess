#include <iostream>
using namespace std;
#include "Board.h" //board.h contains cell.h so non eed to call it

int main()
{
	ChessBoard testBoard;

	testBoard.boardInit(testBoard.board);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//Color cellColor = testBoard.board.boardColor;
		}
	}
}
