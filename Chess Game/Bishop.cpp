#include "Bishop.h"

std::vector<Position> Bishop::highlightMoves(Position current, int boardWidth, int boardLength) {
    std::vector<Position> ret;
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