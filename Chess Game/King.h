#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {

public:
	King(int playerID) : ChessPiece(playerID) {}
	std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

