#include "Pawn.h"

Pawn::Pawn(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Model& pieceModel, Shader& targetShader) : ChessPiece(playerID, position, color, rsMat, pieceModel, targetShader), initMove(true) {}
std::vector<glm::ivec2> Pawn::getMoves(int xLimit, int yLimit) {
	std::vector<glm::ivec2> moves = {};
	glm::ivec2 test;

	if (initMove) {
		moves = { position + glm::ivec2(0,1), position + glm::ivec2(0,2) };
		initMove = !initMove;
	}
	else {
		test = position + glm::ivec2(0, 1);
		if (!ChessPiece::outOfBounds(test, xLimit, yLimit)) moves.push_back(test);
	}

	return moves;
}