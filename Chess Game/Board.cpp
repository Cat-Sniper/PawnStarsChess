#include <string>
#include "Board.h"
#include "Bishop.h"
#include "ChessPiece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

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
			else
				board[i][j].SetWhite();

			if (i == 0 || i == 1 || i == 6 || i == 7) //if within the furst two rows or the last two rows.
			{
				switch (i)
				{
					//CASE 0 AND 1 ARE FOR PLAYER 0 (WHITE)
				case 0: //fill bottom row, passing the column as the argument
					board[i][j].AddChessPiece(CreateBTRow(j , 0));
					break;
				case 1:
					board[i][j].AddChessPiece(CreateChessPiece("pawn", 0));
					break;

					//CASE 6 AND 7 ARE FOR PLAYER 1 (BLACK)
				case 6:
					board[i][j].AddChessPiece(CreateChessPiece("pawn", 1));
					break;
				case 7:
					board[i][j].AddChessPiece(CreateBTRow(j, 1));
					break;
				default: //SHOULD I KEEP THIS?
					board[i][j].RemoveChessPiece();
				}
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
	else
		return false;
}

ChessPiece *ChessBoard::CreateChessPiece(std::string pieceType, int playerID)
{

	if (pieceType == "bishop")
	{
		return new Bishop(playerID);
	}
	else if (pieceType == "king")
	{
		return new King(playerID);
	}
	else if (pieceType == "knight")
	{
		return new Knight(playerID);
	}
	else if (pieceType == "pawn")
	{
		return new Pawn(playerID);
	}
	else if (pieceType == "queen")
	{
		return new Queen(playerID);
	}
	else if (pieceType == "rook")
	{
		return new Rook(playerID);
	}
}

ChessPiece *ChessBoard::CreateBTRow(int columnPosition, int playerID) //based on position in the column (PASS j) it will create the subsequent chess piece, NOTE player 0 is white 1 is black
{
	switch (columnPosition)
	{
		if (columnPosition == 0 || columnPosition == 7)
		{
			return CreateChessPiece("rook", playerID);
		}
		else if (columnPosition == 1 || columnPosition == 6)
		{
			return CreateChessPiece("knight", playerID);
		}
		else if (columnPosition == 2 || columnPosition == 5)
		{
			return CreateChessPiece("bishop", playerID);
		}
		else if (columnPosition == 3)
		{
			return CreateChessPiece("queen", playerID);
		}
		else if (columnPosition == 4)
		{
			return CreateChessPiece("king", playerID);
		}
	}
}

std::vector<Position> ChessBoard::HighlightMoves(ChessPiece *piece, Position current, int boardWidth, int boardLength, ChessBoard gameBoard)
{
	std::vector<Position> moveList = piece->highlightMoves(current, boardWidth, boardLength);

	for (int i = 0; i < moveList.size(); i++)
	{
		Position pos = moveList[i]; // if it's occupied by the same player
		if (gameBoard.board[pos.x][pos.y].isOccupied && gameBoard.board[pos.x][pos.y].currentChessPiece->getPlayerID() == piece->getPlayerID())
		{
			moveList.erase(moveList.begin()); //remove the position from the list of positions
		}
	}

	return moveList;
}
