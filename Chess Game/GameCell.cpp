#include "GameCell.h"

GameCell::GameCell() : piece(nullptr), squareColor(white) {}

GameCell::GameCell(ChessPiece* newPiece, Color& squareColor) : piece(newPiece), squareColor(squareColor) {}

Color& GameCell::getColor() { return squareColor; }
ChessPiece* GameCell::getPiece() { return piece; }

Color& GameCell::setColor(const Color& newSquareColor) {
	Color& oldSquareColor = squareColor;
	squareColor = newSquareColor;
	return oldSquareColor;
}

ChessPiece* GameCell::setPiece(ChessPiece* newPiece) {
	ChessPiece* oldPiece = piece;
	piece = newPiece;
	return oldPiece;
}

GameCell::~GameCell() {}