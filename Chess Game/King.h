#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {
public:
	King(int playerID, glm::mat4 rsMat);
	std::vector<glm::ivec2> getMoves(glm::ivec2 current, int xLimit, int yLimit);
};