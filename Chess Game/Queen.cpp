#include "Queen.h"

std::vector<glm::ivec2> Queen::highlightMoves(glm::ivec2 current, int boardWidth, int boardLength) {
    std::vector<glm::ivec2> ret;
    
    // combine bishop and rook
    for (int i = 0; i < boardLength; ++i) {
         glm::ivec2 file{ current.x, i };
        if (i != current.y) ret.push_back(file);
    }
    for (int i = 0; i < boardWidth; ++i) {
         glm::ivec2 rank{ i, current.y };
        if (i != current.x) ret.push_back(rank);
    }

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