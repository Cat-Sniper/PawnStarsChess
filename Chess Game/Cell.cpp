#include "Cell.h"

#include "ChessPiece.h"
#include <cstddef> //for NULL

//is the cell white/black
//add constructors?

Cell::Cell() //default constructor
{
	_isOccupied = false;
	_currentChessPiece = nullptr; //all cells start without any chess pieces, but a chess piece can be added with a method
}

Cell::~Cell() //default destructor
{

};

void Cell::setWhite()
{
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
}

void Cell::setBlack()
{
	_color.r = 0;
	_color.g = 0;
	_color.b = 0;
}

void Cell::addChessPiece(ChessPiece *piece) //could be created by the ChessPiece class
{
	_currentChessPiece = piece;
	_isOccupied = true;
}

void Cell::removeChessPiece()
{
	if (_currentChessPiece != nullptr) {
		_currentChessPiece = nullptr;
	}
	
}

void Cell::deleteChessPiece()
{
	if (_currentChessPiece != nullptr) {
		delete _currentChessPiece;
		removeChessPiece();
	}
}
