/// Edited: Michael Ward - November 28, 2020

#pragma once
#include "Cell.h"
#include <string>
#include <vector>

// Forward Declaration
class ChessPiece;


class ChessBoard
{
private:
	Cell _board[8][8];

	bool isEven(int i, int j);
	ChessPiece* createBTRow(int columnPosition, int playerID);
	ChessPiece* createChessPiece(std::string pieceType, int playerID);

public:
	ChessBoard();
	~ChessBoard();
	void boardInit();

	ChessPiece* getPieceAtLocation(glm::ivec2 pos) { return _board[pos.x][pos.y].getCurrentChessPiece(); }
	std::vector<glm::ivec2> highlightMoves(ChessPiece *piece, glm::ivec2 current, int boardWidth = 8, int boardLength = 8);
};