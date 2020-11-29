#ifndef TYPES_H
#define TYPES_H

struct Color
{
	float r, g, b;
	Color(float r, float g, float b){
		this->r = r;
		this->g = g;
		this->b = b;
	}

	Color() : r(0.0f), g(0.0f), b(0.0f) {}
};

struct Position {
	int x;
	int	y;
	Position() : x(0), y(0) {}
	Position(int x, int y) : x(0), y(0) {
		this->x = x;
		this->y = y;
	}
};

#endif