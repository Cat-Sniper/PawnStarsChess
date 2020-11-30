#include "ChessPiece.h"

ChessPiece::ChessPiece() {
    _playerID = 0;
    _materialColor.r = 1.0f;
    _materialColor.g = 1.0f;
    _materialColor.b = 1.0f;
    _isAttacked = 0;
    _hasMoved = 0;
    _currentPosition = glm::ivec2(0, 0);
    _isAlive = true;
    _selected = false;
}

ChessPiece::ChessPiece(int playerID) : ChessPiece() {
    setPlayerID(playerID);
}

ChessPiece::~ChessPiece() {

}

int ChessPiece::setPlayerID(int newid) {
    if (newid == 0 || newid == 1) {
        _playerID = newid;
        if (_playerID == 1) {
            _materialColor.r = 0.0f;
            _materialColor.g = 0.0f;
            _materialColor.b = 0.0f;
        }
        else {
            _materialColor.r = 1.0f;
            _materialColor.g = 1.0f;
            _materialColor.b = 1.0f;
        }
        return 0;
    }
    else {
        return 1;
    }
}

std::vector<glm::ivec2> ChessPiece::highlightMoves(glm::ivec2 current, int boardWidth, int boardLength) {
    std::vector<glm::ivec2> ret;
    return ret;
}