#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {

public:
	King(int playerID) : ChessPiece(playerID) {}
	std::vector<glm::ivec2> highlightMoves(glm::ivec2 current, int boardWidth = 8, int boardLength = 8);
};

