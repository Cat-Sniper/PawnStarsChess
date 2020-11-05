#pragma once
#include "Cell.h"
#include "ChessPiece.h"

class ChessBoard
{
	public:
		Cell board [8][8];

	public:
		ChessBoard();
		~ChessBoard();
		void boardInit(Cell board[8][8]);
		bool isEven(int i, int j);
		ChessPiece CreateBTRow(int columnPosition);
		ChessPiece CreateChessPiece(std::string pieceType, int playerID);
		ChessPiece CreatePawn();

};