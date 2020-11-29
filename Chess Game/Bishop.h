#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece {

public:
	Bishop(int playerID) : ChessPiece(playerID) {}
	std::vector<glm::ivec2> highlightMoves(glm::ivec2 current, int boardWidth = 8, int boardLength = 8);
};

