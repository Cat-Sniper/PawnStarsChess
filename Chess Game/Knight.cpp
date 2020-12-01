#include "Knight.h"

Knight::Knight(int playerID, glm::mat4 rsMat) : ChessPiece(playerID, rsMat) {

	_pieceModel = Model(&(RELATIVE_PATH + "knight.obj")[0]);
}
std::vector<glm::ivec2> Knight::getMoves(glm::ivec2 current, int xLimit, int yLimit) {
	
	std::vector<glm::ivec2> ret;

	ret.push_back(glm::ivec2{ current.x - 2, current.y - 1 });
	ret.push_back(glm::ivec2{ current.x - 1, current.y - 2 });
	ret.push_back(glm::ivec2{ current.x + 2, current.y - 1 });
	ret.push_back(glm::ivec2{ current.x + 1, current.y - 2 });
	ret.push_back(glm::ivec2{ current.x + 2, current.y + 1 });
	ret.push_back(glm::ivec2{ current.x + 1, current.y + 2 });
	ret.push_back(glm::ivec2{ current.x - 2, current.y + 1 });
	ret.push_back(glm::ivec2{ current.x - 1, current.y + 2 });

	auto i = ret.begin();
	while (i != ret.end()) {
		if (outOfBounds((*i), xLimit, yLimit)) i = ret.erase(i);
		else ++i;
	}
	

	return ret;
}
