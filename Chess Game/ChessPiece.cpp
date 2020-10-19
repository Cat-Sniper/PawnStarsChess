#include "ChessPiece.h"

ChessPiece::ChessPiece() {
    _playerID = 0;
    _materialColor.r = 0;
    _materialColor.g = 0;
    _materialColor.b = 0;
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
            _materialColor.r = 255;
            _materialColor.g = 255;
            _materialColor.b = 255;
        }
        else {
            _materialColor.r = 0;
            _materialColor.g = 0;
            _materialColor.b = 0;
        }
        return 0;
    }
    else {
        return 1;
    }
}

std::vector<Position> ChessPiece::highlightMoves(Position current, int boardWidth = 8, int boardLength = 8) {
    std::vector<Position> ret;
    return ret;
}