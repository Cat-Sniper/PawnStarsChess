#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {

public:
	Rook(int playerID, glm::mat4& rsMat, Shader& targetShader);
	std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};

