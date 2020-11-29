#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {
public:
	Rook(int playerID) : ChessPiece(playerID) {}
	std::vector<glm::ivec2> highlightMoves(glm::ivec2 current, int boardWidth = 8, int boardLength = 8);
};

