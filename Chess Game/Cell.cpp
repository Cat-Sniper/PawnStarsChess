#include "Cell.h"
#include <cstddef> //for NULL

//is the cell white/black
//add constructors?



class Cell
{
public:
	Color boardColor;
	bool isOccupied;
	ChessPiece currentChessPiece = NULL; //all cells start without any chess pieces, but a chess piece can be added with a method


public:
	Cell() //default constructor
	{
		isOccupied = false;
		currentChessPiece = NULL;
	}

	~Cell() //default destructor
	{

	}

	void SetWhite()
	{
		boardColor.r = 255;
		boardColor.r = 255;
		boardColor.r = 255;
	}

	void SetBlack()
	{
		boardColor.r = 0;
		boardColor.g = 0;
		boardColor.b = 0;
	}

	void AddChessPiece(ChessPiece piece)//could be created by the ChessPiece class
	{
		currentChessPiece = piece;
		isOccupied = true;
	}

	void RemoveChessPiece()
	{
		currentChessPiece = NULL;
	}
};


