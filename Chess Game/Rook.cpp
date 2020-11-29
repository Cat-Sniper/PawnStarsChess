#include "Rook.h"

std::vector<glm::ivec2> Rook::highlightMoves(glm::ivec2 current, int boardWidth, int boardLength) {
    std::vector<glm::ivec2> ret;
    for (int i = 0; i < boardLength; ++i) {
         glm::ivec2 file{ current.x, i };
        if (i != current.y) ret.push_back(file);
    }
    for (int i = 0; i < boardWidth; ++i) {
         glm::ivec2 rank{ i, current.y };
        if (i != current.x) ret.push_back(rank);
    }
    return ret;
}