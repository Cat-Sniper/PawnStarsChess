#include "Rook.h"

std::vector<Position> Rook::highlightMoves(Position current, int boardWidth = 8, int boardLength = 8) {
    std::vector<Position> ret;
    for (int i = 0; i < boardLength; ++i) {
        Position file{ current.x, i };
        if (i != current.y) ret.push_back(file);
    }
    for (int i = 0; i < boardWidth; ++i) {
        Position rank{ i, current.y };
        if (i != current.x) ret.push_back(rank);
    }
    return ret;
}