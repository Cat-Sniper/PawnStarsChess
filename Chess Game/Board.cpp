#include <string>
#include "Board.h"
#include "Bishop.h"
#include "ChessPiece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
//MUST INCLUDE CHESSPIECE FILES

//cell board array
//highlight move method, reach into the cell and the currentchesspiece to figure out possible moves (using the piece's position)

//questions: how do I merge since my Branch is behind on updates?
//do I allocate on the heap? Is that the only way?
//finish highlight moves class
//have to close soln file 



ChessBoard::ChessBoard()
{

}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::BoardInit(Cell board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (IsEven(i, j)) //COLORS THE BOARD ROW BY ROW
			{
				board[i][j].SetBlack();
			}
			else board[i][j].SetWhite();

			if (i == 0 || i == 1) //if within the first row (where white pieces are)
			{
				switch (i)
				{
				case 0: //fill pieces rook to rook
					//board[i][j].currentChessPiece = CreateBTRow(j);
					break;
				case 1:
					//board[i][j].currentChessPiece = CreatePawnRow();
					break;
				}

			}
			if (i == 6 || i == 7) //do I instantiate a chesspiece for each case and insert it into the function? - Also have to make switch cases for each piece
			{

			}
		}

	}

}

bool ChessBoard::IsEven(int i, int j)
{
	if ((i + j) % 2 == 0)
	{
		return true;
	}
	else return false;
}

ChessPiece ChessBoard::CreateChessPiece(std::string pieceType, int playerID)
{
	
	if (pieceType == "bishop")
	{
		Bishop piece;
		return piece;

	}
	else if (pieceType == "king")
	{
		King piece;
		return piece;
	}
	else if (pieceType == "knight")
	{
		Knight piece;
		return piece;
	}
	else if (pieceType == "pawn")
	{
		Pawn piece;
		return piece;
	}
	else if (pieceType == "queen")
	{
		Queen piece;
		return piece;
	}
	else if (pieceType == "rook")
	{
		Rook piece;
		return piece;
	}
	
}


/*ChessPiece ChessBoard::CreateBTRow(int columnPosition)//based on position in the column (PASS j) it will create the subsequent chess piece
{
	switch (columnPosition)
	{
		if (columnPosition == 0 || columnPosition == 7) //rook
		{
			ChessPiece piece = new ChessPiece("rook");
			return piece;
		}
		else if (columnPosition == 1 || columnPosition == 6)
		{
			ChessPiece piece = new ChessPiece("")
		}
	}
}

/*ChessPiece ChessBoard::CreatePawn()


		/*ChessPiece CreatePawn()
		{
		}
		




};*/