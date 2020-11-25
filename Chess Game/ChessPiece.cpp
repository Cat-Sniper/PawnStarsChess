#include "ChessPiece.h"

ChessPiece::ChessPiece() {
    _playerID = 0;
    _materialColor.r = 1.0f;
    _materialColor.g = 1.0f;
    _materialColor.b = 1.0f;
    _isAttacked = 0;
    _hasMoved = 0;
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

std::vector<Position> ChessPiece::highlightMoves(Position current, int boardWidth, int boardLength) {
    std::vector<Position> ret;
    return ret;
}