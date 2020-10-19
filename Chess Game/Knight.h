#pragma once
#include "ChessPiece.h"
class Knight :
    public ChessPiece {
public:
    std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

