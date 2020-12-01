#include "Queen.h"

Queen::Queen(int playerID, glm::mat4 rsMat) : ChessPiece(playerID, rsMat) {
	
	_pieceModel = Model(&(RELATIVE_PATH + "Queen.obj")[0]);
}

std::vector<glm::ivec2> Queen::getMoves(glm::ivec2 current, int xLimit, int yLimit) {
     std::vector<glm::ivec2> ret;

     // combine bishop and rook
     for (int i = 0; i < yLimit; ++i) {
          glm::ivec2 file{ current.x, i };
          if (i != current.y) ret.push_back(file);
     }
     for (int i = 0; i < xLimit; ++i) {
          glm::ivec2 rank{ i, current.y };
          if (i != current.x) ret.push_back(rank);
     }

     glm::ivec2 next = current;
     while (next.x < xLimit && next.y < yLimit) {
          next.x++;
          next.y++;
          ret.push_back(next);
     }
     next = current;
     while (next.x >= 0 && next.y < yLimit) {
          next.x--;
          next.y++;
          ret.push_back(next);
     }
     next = current;
     while (next.x < xLimit && next.y >= 0) {
          next.x++;
          next.y--;
          ret.push_back(next);
     }
     next = current;
     while (next.x >= 0 && next.y >= 0) {
          next.x--;
          next.y--;
          ret.push_back(next);
     }
     return ret;
}
