#pragma once
#include "ChessPiece.h"
class Pawn : public ChessPiece {
private:
	bool initMove;

public:

	Pawn(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Shader& targetShader);
	std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};

