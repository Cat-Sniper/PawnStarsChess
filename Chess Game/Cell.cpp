#include "Cell.h"
#include <cstddef> //for NULL

//is the cell white/black
//add constructors?

Cell::Cell() //default constructor
{
	isOccupied = false;
	currentChessPiece = nullptr; //all cells start without any chess pieces, but a chess piece can be added with a method
}

Cell::~Cell() //default destructor
	{

	};

void Cell::SetWhite()
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
}

void Cell::SetBlack()
{
	color.r = 0;
	color.g = 0;
	color.b = 0;
}

void Cell::AddChessPiece(ChessPiece *piece) //could be created by the ChessPiece class
{
	currentChessPiece = piece;
	isOccupied = true;
}

void Cell::RemoveChessPiece()
{
	currentChessPiece = NULL;
}
