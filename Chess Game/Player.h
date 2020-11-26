#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_set>
#include "ChessPiece.h"




#pragma once
/// <summary>
/// 
/// </summary>
class Player
{
	public:
		Player();
		~Player();
		takeTurn();

	private:
		int _player_id;
		std::unordered_multiset<ChessPiece> _pieces;


};




#endif // !PLAYER_H