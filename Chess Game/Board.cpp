#include <string>

//cell board array
//highlight move method, reach into the cell and the currentchesspiece to figure out possible moves (using the piece's position)


class ChessBoard
{
public:
	Cell [8][8] board;


public:
	void boardInit(Cell board[8][8])
	{
		for (int i = 0; i > 8; i++)
		{
			for (int j = 0; j > 8; j++)
			{
				if(isEven(i,j))
				{ 
					board[i][j].setBlack();
				}
				else board[i][j].setWhite();

				switch (board[i][j]) //do I instantiate a chesspiece for each case and insert it into the function?
				{

				}
			}

		}

	}



	bool isEven(int i, int j)
	{
		if ((i + j) % 2 == 0)
		{
			return true;
		}
		else return false;
	}



};