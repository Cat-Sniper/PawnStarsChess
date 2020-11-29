#ifndef TYPES_H
#define TYPES_H

#include "glm/glm.hpp"

// GLOBAL STRUCTS
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

// GLOBAL CONSTANTS
const Color PLAYER1_COLOR = Color(1.0, 0.5, 0.31);
const Color PLAYER2_COLOR = Color(92 / 255.0f, 225 / 255.0f, 230 / 255.0f);
#endif