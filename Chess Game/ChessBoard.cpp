/// ChessBoard.cpp
/// -----------------------------------------
/// 8x8 grid composed of 'Cells' who know which ChessPiece is sitting on them.
/// Created Ashraf 
#include <string>
#include "ChessBoard.h"

// Reference headers
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
	// Delete all chess pieces that were added to the heap
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) {
			
			if (_board[i][j].getCurrentChessPiece() != nullptr) delete _board[i][j].getCurrentChessPiece();
		}
	}
}

void ChessBoard::boardInit()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (isEven(i, j)) //COLORS THE BOARD ROW BY ROW
			{
				_board[i][j].setBlack();
			}
			else
				_board[i][j].setWhite();

			if (i == 0 || i == 1 || i == 6 || i == 7) //if within the furst two rows or the last two rows.
			{
				switch (i)
				{
					//CASE 0 AND 1 ARE FOR PLAYER 0 (WHITE)
				case 0: //fill bottom row, passing the column as the argument
					_board[i][j].addChessPiece(createBTRow(j , 0));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i,j));
					break;
				case 1:
					_board[i][j].addChessPiece(createChessPiece("pawn", 0));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i, j));
					break;

					//CASE 6 AND 7 ARE FOR PLAYER 1 (BLACK)
				case 6:
					_board[i][j].addChessPiece(createChessPiece("pawn", 1));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i, j));
					break;
				case 7:
					_board[i][j].addChessPiece(createBTRow(j, 1));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i, j));
					break;
				default: //SHOULD I KEEP THIS?
					_board[i][j].removeChessPiece();
				}
			}
		}
	}
}

bool ChessBoard::isEven(int i, int j)
{
	if ((i + j) % 2 == 0)
	{
		return true;
	}
	else
		return false;
}

ChessPiece *ChessBoard::createChessPiece(std::string pieceType, int playerID)
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

ChessPiece *ChessBoard::createBTRow(int columnPosition, int playerID) //based on position in the column (PASS j) it will create the subsequent chess piece, NOTE player 0 is white 1 is black
{
	switch (columnPosition)
	{
		if (columnPosition == 0 || columnPosition == 7)
		{
			return createChessPiece("rook", playerID);
		}
		else if (columnPosition == 1 || columnPosition == 6)
		{
			return createChessPiece("knight", playerID);
		}
		else if (columnPosition == 2 || columnPosition == 5)
		{
			return createChessPiece("bishop", playerID);
		}
		else if (columnPosition == 3)
		{
			return createChessPiece("queen", playerID);
		}
		else if (columnPosition == 4)
		{
			return createChessPiece("king", playerID);
		}
	}
}

std::vector<glm::ivec2> ChessBoard::highlightMoves(ChessPiece *piece, glm::ivec2 current, int boardWidth, int boardLength)
{
	std::vector<glm::ivec2> moveList = piece->highlightMoves(current, boardWidth, boardLength);

	for (int i = 0; i < moveList.size(); i++)
	{
		glm::ivec2 pos = moveList[i]; // if it's occupied by the same player
		if (_board[pos.x][pos.y].isOccupied() && _board[pos.x][pos.y].getCurrentChessPiece()->getPlayerID() == piece->getPlayerID())
		{
			moveList.erase(moveList.begin()); //remove the position from the list of positions
		}
	}

	return moveList;
}
