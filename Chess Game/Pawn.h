#pragma once
#include "ChessPiece.h"
class Pawn : public ChessPiece {
private:
	bool initMove;

public:

	Pawn(int playerID, glm::mat4 rsMat);
	std::vector<glm::ivec2> getMoves(glm::ivec2 current, int xLimit, int yLimit);
};

