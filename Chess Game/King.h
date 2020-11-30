#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {
public:
	King(int playerID, glm::mat4& rsMat, Shader& targetShader);
	std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};