/// "Player.h"
/// ----------------------------------
/// There are two players in chess. This class helps identify who is who.
/// Author: Michael Ward - November 26, 2020
/// Edited: Michael Ward - November 28, 2020
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

// Forward declaration
class ChessPiece;

/// <summary>
/// The player class: contains information relevant to each player: What pieces they have, which colour they are etc.
/// </summary>
class Player {

private:
	int _id;								// 0 or 1 aka white or black
	std::vector<ChessPiece*> _pieces;			// vector of all 16 chess pieces

public:
	Player(int id);
	void takeTurn();
	int getID() { return _id; }
	std::vector<ChessPiece*>& getPieces() { return _pieces; }
};
#endif