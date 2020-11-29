#include "Knight.h"

std::vector<glm::ivec2> Knight::highlightMoves(glm::ivec2 current, int boardWidth, int boardLength) {
    std::vector<glm::ivec2> ret;

    ret.push_back(glm::ivec2{ current.x - 2, current.y - 1 });
    ret.push_back(glm::ivec2{ current.x - 1, current.y - 2 });
    ret.push_back(glm::ivec2{ current.x + 2, current.y - 1 });
    ret.push_back(glm::ivec2{ current.x + 1, current.y - 2 });
    ret.push_back(glm::ivec2{ current.x + 2, current.y + 1 });
    ret.push_back(glm::ivec2{ current.x + 1, current.y + 2 });
    ret.push_back(glm::ivec2{ current.x - 2, current.y + 1 });
    ret.push_back(glm::ivec2{ current.x - 1, current.y + 2 });

    for (std::vector<glm::ivec2>::iterator it = ret.begin(); it != ret.end(); it++) {
        if (isOutOfBounds(*it, boardWidth, boardLength)) ret.erase(it);
    }

    return ret;
}