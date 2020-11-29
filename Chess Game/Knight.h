#pragma once
#include "ChessPiece.h"
class Knight : public ChessPiece {

public:
	Knight(int playerID) : ChessPiece(playerID) {}
	std::vector<glm::ivec2> highlightMoves(glm::ivec2 current, int boardWidth = 8, int boardLength = 8);
};

