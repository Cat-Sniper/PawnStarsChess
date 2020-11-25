#ifndef GAME_CELL
#define GAME_CELL
#include "ChessPiece.h"
#include "GlobalTypes.h"

Color black = Color();
Color white = Color(1.0f, 1.0f, 1.0f);

class GameCell {
private:
	ChessPiece* piece;
	Color& squareColor;

public:
	GameCell();
	GameCell(ChessPiece* newPiece, Color& squareColor);
	~GameCell();

	ChessPiece* getPiece();
	Color& getColor();

	//Setters will return the old value
	ChessPiece* setPiece(ChessPiece* newPiece);
	Color& setColor(const Color& newSquareColor);
};

#endif
