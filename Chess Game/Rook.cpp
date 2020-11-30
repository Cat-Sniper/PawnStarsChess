#include "Rook.h"

Rook::Rook(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Model& pieceModel, Shader& targetShader) : ChessPiece(playerID, position, color, rsMat, pieceModel, targetShader) {}
std::vector<glm::ivec2> Rook::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves;
	std::vector<glm::ivec2> testVecs = { glm::ivec2(1,0), glm::ivec2(-1,0), glm::ivec2(0,1), glm::ivec2(0,-1) };
	glm::ivec2 test;

	for (int i = 0; i < testVecs.size(); i++) {
		for (int j = 0; ; j++) {
			test = position + (j * testVecs[i]);
			if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) {
				moves.push_back(glm::ivec2(test));
			}
			else {
				break;
			}
		}
	}

	return moves;
}