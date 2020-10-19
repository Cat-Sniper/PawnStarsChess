#include "Pawn.h"

std::vector<Position> Pawn::highlightMoves(Position current, int boardWidth = 8, int boardLength = 8) {
    std::vector<Position> ret;
    Position next = current;
    if (getPlayerID() == 0) {  // black pieces
        next.y++;
        if (next.y < boardLength) ret.push_back(next);

        // if pawn has never moved, it has the option to move 2 cells ahead.
        if (!hasMoved()) {
            next.y++;
            ret.push_back(next);  // no need to check for bounds here
        }
    }
    else {  // white pieces
        next.y--;
        if (next.y >= 0) ret.push_back(next);
        if (!hasMoved()) {
            next.y--;
            ret.push_back(next);
        }
    }

    return ret;
}