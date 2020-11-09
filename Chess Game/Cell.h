#pragma once
#include "GlobalTypes.h"
#include "ChessPiece.h"

class Cell
{
	public:
		Color color;
		bool isOccupied;
		ChessPiece currentChessPiece;

	public:
		Cell();
		~Cell();
		void SetWhite();
		void SetBlack();
		void AddChessPiece(ChessPiece piece);
		void RemoveChessPiece();
};