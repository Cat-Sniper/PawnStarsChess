/// "ChessPiece.h"
/// ----------------------------------
/// The abstract class ChestPiece, from which all the specific pieces are derived.
/// Author: Yile Zhu

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "GlobalTypes.h"
#include <vector>

class ChessPiece {
public:
    /// <summary>
    /// the default constructor. _playerID is set to 0 and piece color is set to black (rgb(0,0,0)).
    /// </summary>
    ChessPiece();

    /// <summary>
    /// this calls the default constructor before setting _playerID to the given playerID.
    /// </summary>
    /// <param name="playerID"> the given playerID. can be 1 or 0. </param>
    ChessPiece(int playerID);

    ~ChessPiece();

    /// <summary>
    /// 
    /// </summary>
    /// <returns> value of _playerID. </returns>
    inline int getPlayerID() {
        return _playerID;
    }

    /// <summary>
    /// sets _playerID to the given newid.
    /// </summary>
    /// <param name="newid"></param>
    /// <returns> returns 0 if operation is successful, 1 otherwise (e.g. when parameter is illegal) </returns>
    int setPlayerID(int newid);

    /// <summary>
    /// Used for checking if a piece is under attack.
    /// </summary>
    /// <returns> returns 1 if the chess piece is under attack by an opposite piece, 0 otherwise.</returns>
    inline int isAttacked() {
        return _isAttacked;
    }

    /// <summary>
    /// the chess board should call this whenever a piece becomes under attack, or when the threat is remedied.
    /// e.g. when the King is in check, and when it gets out of one.
    /// </summary>
    inline void flipState() {
        _isAttacked = _isAttacked ? 0 : 1;
    }

    /// <summary>
    /// ideally you would call this every time a piece moves. 
    /// </summary>
    inline void move() {
        _hasMoved = 1;
    }

    inline void reset() {
        _hasMoved = 0;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns> 0 if the piece has not moved since start of the game, 1 otherwise. </returns>
    inline int hasMoved() {
        return _hasMoved;
    }

    inline int isOutOfBounds(Position pos, int x, int y) {
        return !((pos.x >= 0) && (pos.y >= 0) && (pos.x < x) && (pos.y < y));
    }

    /// <summary>
    /// this method calculates all the valid moves for this chess piece and returns a vector of board positions
    /// containing all the valid move positions. it does so without knowledge of the current state of the chess
    /// board, so the chess board is responsible for checking if any position is blocked or occupied by other
    /// pieces.
    /// 
    /// black pieces are assumed to be at the bottom of the board. Position starts from (0, 0) from the bottom
    /// left of the board.
    /// </summary>
    /// <param name="current"> the current position of this chess piece. </param>
    /// <param name="boardWidth"> the width of the board, defaults to 8. </param>
    /// <param name="boardLength"> the lengtht of the board, defaults to 8. </param>
    /// <returns> without overriding, this returns an empty vector. </returns>
    virtual std::vector<Position> highlightMoves(Position current, int boardWidth = 8, int boardLength = 8);

    /// <summary>
    /// Returns whether or not the piece is alive. If it isn't, it will no longer be updated or rendered.
    /// </summary>
    inline bool isAlive() { return _isAlive; }

    /// <summary>
    /// All the rendering stuff will be here.
    /// </summary>
    void Render();
protected:
    // ChessBoard* chessboard;  <- should not be a dependency; i'm not sure we need this
    int _playerID;
    Color _materialColor;
    int _isAttacked;  // 1 if piece is under attack by an opposite piece, 0 otherwise.
    int _hasMoved;
    bool _isAlive;     // should we even draw it?
};

#endif  // CHESSPIECE_H