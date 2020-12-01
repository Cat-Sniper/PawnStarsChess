#include "Pawn.h"

Pawn::Pawn(int playerID, glm::mat4 rsMat) : ChessPiece(playerID, rsMat), initMove(true) {

	_pieceModel = Model(&(RELATIVE_PATH + "Pawn.obj")[0]);
}

std::vector<glm::ivec2> Pawn::getMoves(glm::ivec2 current, int xLimit, int yLimit) {
     std::vector<glm::ivec2> ret;
     glm::ivec2 next = current;
     if (_playerID == 0) {  // black pieces
          next.y++;
          if (next.y < yLimit) ret.push_back(next);

          // if pawn has never moved, it has the option to move 2 cells ahead.
          if (!initMove) {
               next.y++;
               ret.push_back(next);  // no need to check for bounds here
          }
     }
     else {  // white pieces
          next.y--;
          if (next.y >= 0) ret.push_back(next);
          if (!initMove) {
               next.y--;
               ret.push_back(next);
          }
     }

     return ret;
}
