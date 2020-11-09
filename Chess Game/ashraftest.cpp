#include <iostream>
using namespace std;
#include "Board.h" //board.h contains cell.h so non eed to call it

int main()
{
	ChessBoard testBoard;

	testBoard.BoardInit(testBoard.board);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			/*Color cellColor = testBoard.board[i][j].color;
			std::cout << cellColor.r;
			std::cout << cellColor.g;
			std::cout << cellColor.b;*/

			std::cout << testBoard.board[i][j].isOccupied;
		}
	}

}

