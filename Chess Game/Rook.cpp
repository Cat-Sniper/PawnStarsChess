#include "Rook.h"

std::vector<Position> Rook::highlightMoves(Position current, int boardWidth, int boardLength) {
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