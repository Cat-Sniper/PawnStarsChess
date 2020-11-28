#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece {

public:
	Bishop(int playerID) : ChessPiece(playerID) {}
	std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

