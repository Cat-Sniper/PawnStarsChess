#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {
public:
	Rook(int playerID) : ChessPiece(playerID) {}
	std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

