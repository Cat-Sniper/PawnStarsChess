#pragma once
#include "ChessPiece.h"
class King :
    public ChessPiece {
    std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

