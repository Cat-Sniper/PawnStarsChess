#include "Pawn.h"

Pawn::Pawn(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Shader& targetShader) : ChessPiece(playerID, position, color, rsMat, targetShader), initMove(true) {

	_pieceModel = Model(&(RELATIVE_PATH + "Pawn.obj")[0]);
}

std::vector<glm::ivec2> Pawn::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves = {};
	glm::ivec2 test;

	if (initMove) {
		moves = { _position + glm::ivec2(0,1), _position + glm::ivec2(0,2) };
		initMove = !initMove;
	}
	else {
		test = _position + glm::ivec2(0, 1);
		if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) moves.push_back(test);
	}

	return moves;
}
