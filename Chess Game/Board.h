#pragma once
#include "Cell.h"
#include "ChessPiece.h"

class ChessBoard
{
public:
	Cell board[8][8];

public:
	ChessBoard();
	~ChessBoard();
	void BoardInit(Cell board[8][8]);
	bool IsEven(int i, int j);
	ChessPiece *CreateBTRow(int columnPosition);
	ChessPiece *CreateChessPiece(std::string pieceType);
	std::vector<Position> HighlightMoves(ChessPiece *piece, Position current, int boardWidth, int boardLength, ChessBoard gameBoard);
};