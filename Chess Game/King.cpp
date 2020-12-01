#include "King.h"

King::King(int playerID, glm::mat4 rsMat) : ChessPiece(playerID, rsMat) {

	_pieceModel = Model(&(RELATIVE_PATH + "King.obj")[0]);
}

std::vector<glm::ivec2> King::getMoves(glm::ivec2 current, int xLimit, int yLimit) {
	std::vector<glm::ivec2> ret;

	ret.push_back(glm::ivec2{ current.x - 1, current.y });
	ret.push_back(glm::ivec2{ current.x + 1, current.y });
	ret.push_back(glm::ivec2{ current.x, current.y - 1 });
	ret.push_back(glm::ivec2{ current.x, current.y + 1 });
	ret.push_back(glm::ivec2{ current.x - 1, current.y - 1 });
	ret.push_back(glm::ivec2{ current.x + 1, current.y + 1 });
	ret.push_back(glm::ivec2{ current.x + 1, current.y - 1 });
	ret.push_back(glm::ivec2{ current.x - 1, current.y + 1 });

	for (std::vector<glm::ivec2>::iterator it = ret.begin(); it != ret.end(); it++) {
		if (outOfBounds(*it, xLimit, yLimit)) ret.erase(it);
	}

	return ret;
}
