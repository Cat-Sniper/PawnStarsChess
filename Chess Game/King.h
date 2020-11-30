#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {

public:
	King(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Model& pieceModel, Shader& targetShader);
	std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};