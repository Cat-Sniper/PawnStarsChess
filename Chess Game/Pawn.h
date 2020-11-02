#pragma once
#include "ChessPiece.h"
class Pawn :
    public ChessPiece {
    /// <summary>
    /// missing the move option when the pawn can capture enemy pieces (it does so by going diagonally forward 1 cell)
    /// so the board must add that option when possible.
    /// </summary>
    /// <param name="current"></param>
    /// <param name="boardWidth"></param>
    /// <param name="boardLength"></param>
    /// <returns></returns>
    std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);
};

