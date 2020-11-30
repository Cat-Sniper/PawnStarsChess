#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece {
public:

	Bishop(int playerID, glm::mat4& rsMat, Shader& targetShader);
	std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};

