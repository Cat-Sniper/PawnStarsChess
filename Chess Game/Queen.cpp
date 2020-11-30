#include "Queen.h"

Queen::Queen(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Shader& targetShader) : ChessPiece(playerID, position, color, rsMat, targetShader) {
	
	_pieceModel = Model(&(RELATIVE_PATH + "Queen.obj")[0]);
}

std::vector<glm::ivec2> Queen::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves;
	std::vector<glm::ivec2> testVecs = { glm::ivec2(1,1), glm::ivec2(-1,1), glm::ivec2(-1,-1), glm::ivec2(1,-1), glm::ivec2(1,0), glm::ivec2(-1,0), glm::ivec2(0,1), glm::ivec2(0,-1) };
	glm::ivec2 test;

	for (int i = 0; i < testVecs.size(); i++) {//for each vector
		for (int j = 1; ; j++) {//test positive scalar multiples
			test = _position + (j * testVecs[i]);
			if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) {
				moves.push_back(glm::vec2(test));
			}
			else {
				break;
			}
		}
	}

	return moves;
}
