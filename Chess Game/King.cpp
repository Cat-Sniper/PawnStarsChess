#include "King.h"

King::King(int playerID, glm::mat4& rsMat, Shader& targetShader) : ChessPiece(playerID, rsMat, targetShader) {

	_pieceModel = Model(&(RELATIVE_PATH + "King.obj")[0]);
}

std::vector<glm::ivec2> King::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves;
	std::vector<glm::ivec2> testMoves = { glm::ivec2(1,0), glm::ivec2(-1,0), glm::ivec2(0,1), glm::ivec2(0,-1) };
	
	for (int i = 0; i < testMoves.size(); i++) {
		glm::ivec2 test = _position + testMoves[i];
		if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) moves.push_back(glm::vec2(test));
	}

	return moves;
}
