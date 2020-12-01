#include "Rook.h"

Rook::Rook(int playerID, glm::mat4 rsMat) : ChessPiece(playerID, rsMat) {
	_pieceModel = Model(&(RELATIVE_PATH + "Rook.obj")[0]);
}

std::vector<glm::ivec2> Rook::getMoves(glm::ivec2 current, int xLimit, int yLimit) {
     std::vector<glm::ivec2> ret;
     for (int i = 0; i < yLimit; ++i) {
          glm::ivec2 file{ current.x, i };
          if (i != current.y) ret.push_back(file);
     }
     for (int i = 0; i < xLimit; ++i) {
          glm::ivec2 rank{ i, current.y };
          if (i != current.x) ret.push_back(rank);
     }
     return ret;
}

