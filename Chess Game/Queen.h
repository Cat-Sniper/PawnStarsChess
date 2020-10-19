#pragma once
#include "ChessPiece.h"
class Queen :
    public ChessPiece {
    std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

