#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece {
public:
	Queen(int playerID, glm::mat4& rsMat, Shader& targetShader);
	std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};

