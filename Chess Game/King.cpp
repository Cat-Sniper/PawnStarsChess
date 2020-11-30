#include "King.h"

King::King(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Model& pieceModel, Shader& targetShader) : ChessPiece(playerID, position, color, rsMat, pieceModel, targetShader) {}

std::vector<glm::ivec2> King::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves;
	std::vector<glm::ivec2> testMoves = { glm::ivec2(1,0), glm::ivec2(-1,0), glm::ivec2(0,1), glm::ivec2(0,-1) };
	
	for (int i = 0; i < testMoves.size(); i++) {
		glm::ivec2 test = position + testMoves[i];
		if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) moves.push_back(glm::vec2(test));
	}

	return moves;
}