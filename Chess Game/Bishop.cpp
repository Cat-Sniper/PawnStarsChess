#include "Bishop.h"

Bishop::Bishop(int playerID, glm::mat4 rsMat) : ChessPiece(playerID, rsMat) {
	_pieceModel = Model(&(RELATIVE_PATH + "Bishop.obj")[0]);
}
std::vector<glm::ivec2> Bishop::getMoves(glm::ivec2 current, int xLimit, int yLimit) {
     std::vector<glm::ivec2> ret;
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
