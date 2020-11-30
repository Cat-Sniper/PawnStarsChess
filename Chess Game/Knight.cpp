#include "Knight.h"

Knight::Knight(int playerID, glm::mat4& rsMat, Shader& targetShader) : ChessPiece(playerID, rsMat, targetShader) {

	_pieceModel = Model(&(RELATIVE_PATH + "knight.obj")[0]);
}
std::vector<glm::ivec2> Knight::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves;
	std::vector<glm::ivec2> testVecs = { glm::ivec2(2, 1), glm::ivec2(1,2), glm::ivec2(2, -1), glm::ivec2(1, -2), glm::ivec2(-1, -2), glm::ivec2(-2, -1), glm::ivec2(-2, 1), glm::ivec2(-1, 2) };
	glm::ivec2 test;

	for (int i = 0; i < testVecs.size(); i++) {
		test = _position + testVecs[i];
		if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) moves.push_back(glm::ivec2(test));
	}

	return moves;
}
