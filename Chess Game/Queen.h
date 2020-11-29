#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece {

public:
	Queen(int playerID) : ChessPiece(playerID) {}
    std::vector<glm::ivec2> highlightMoves(glm::ivec2 current, int boardWidth = 8, int boardLength = 8);
};

