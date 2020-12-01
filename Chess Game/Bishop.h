#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece {
public:

	Bishop(int playerID, glm::mat4 rsMat);
	std::vector<glm::ivec2> getMoves(glm::ivec2 current, int xLimit, int yLimit);
};

