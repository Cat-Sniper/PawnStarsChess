#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece {

public:
	Queen(int playerID) : ChessPiece(playerID) {}
    std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

