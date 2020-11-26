#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class ChessPiece;

class Player {

private:
	int _id;								// 0 or 1 aka white or black
	std::vector<ChessPiece*> _pieces;			// vector of all 16 chess pieces
	
public:
	Player(int id);

	std::vector<ChessPiece*>& getPieces() { return _pieces; }
};
#endif