#include "GlobalTypes.h"
#include <cstddef> //for NULL

//is the cell white/black




class Cell
{
public:
	Color BoardColor;

	//ChessPiece  currentChessPiece = NULL; //all cells start without any chess pieces, but a chess piece can be added with a method


public:
	void setWhite()
	{
		BoardColor.r = 255;
		BoardColor.r = 255;
		BoardColor.r = 255;
	}

	void setBlack()
	{
		BoardColor.r = 0;
		BoardColor.g = 0;
		BoardColor.b = 0;
	}

	void addChessPiece(ChessPiece type)
	{
		//this.currentChessPiece = type;
	}

	bool isOccupied(int cellLocation)
	{
		if (this.currentChessPiece = NULL)
			return false;
		else
			return true;
	}




}

int main()
{

}




//is there a chess piece currently on this cell? -- WHAT METHOD AM I CODING?

