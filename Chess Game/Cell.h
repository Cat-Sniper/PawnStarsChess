/// Edited: Michael Ward - November 28, 2020

#pragma once
#include "GlobalTypes.h"

class ChessPiece;

class Cell
{
private:
	Color _color;
	ChessPiece* _currentChessPiece;
	bool _isOccupied;

public:
	Cell();
	~Cell();
	void setWhite();
	void setBlack();
	void addChessPiece(ChessPiece *piece);
	void removeChessPiece();
	void deleteChessPiece();
	bool isOccupied() { return _isOccupied; }
	ChessPiece* getCurrentChessPiece();

};