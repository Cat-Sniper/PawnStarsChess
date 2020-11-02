#include "Queen.h"

std::vector<Position> Queen::highlightMoves(Position current, int boardWidth = 8, int boardLength = 8) {
    std::vector<Position> ret;
    
    // combine bishop and rook
    for (int i = 0; i < boardLength; ++i) {
        Position file{ current.x, i };
        if (i != current.y) ret.push_back(file);
    }
    for (int i = 0; i < boardWidth; ++i) {
        Position rank{ i, current.y };
        if (i != current.x) ret.push_back(rank);
    }

    Position next = current;
    while (next.x < boardWidth && next.y < boardLength) {
        next.x++;
        next.y++;
        ret.push_back(next);
    }
    next = current;
    while (next.x >= 0 && next.y < boardLength) {
        next.x--;
        next.y++;
        ret.push_back(next);
    }
    next = current;
    while (next.x < boardWidth && next.y >= 0) {
        next.x++;
        next.y--;
        ret.push_back(next);
    }
    next = current;
    while (next.x >= 0 && next.y >= 0) {
        next.x--;
        next.y--;
        ret.push_back(next);
    }
    return ret;
}