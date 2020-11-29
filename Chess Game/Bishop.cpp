#include "Bishop.h"

std::vector<glm::ivec2> Bishop::highlightMoves(glm::ivec2 current, int boardWidth, int boardLength) {
    std::vector<glm::ivec2> ret;
    glm::ivec2 next = current;
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