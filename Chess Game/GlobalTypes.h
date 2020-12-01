#ifndef TYPES_H
#define TYPES_H

#include "glm/glm.hpp"
#include <string>

#include "Shader.h"

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

// Character for on screen text
struct Character {
	unsigned int TextureID;	// ID handle of the glyph texture
	glm::ivec2 Size;		// Size of glyph
	glm::ivec2 Bearing;		// Offset from baseline to left/top of glyph
	unsigned int Advance;	// Offset to advance to next glyph
};

// GLOBAL CONSTANTS
const Color PLAYER1_COLOR = Color(255 / 255.0f, 254 / 255.0f, 238 / 255.0f);
const Color PLAYER2_COLOR = Color(152 / 255.0f, 99 / 255.0f, 59 / 255.0f);
const std::string RELATIVE_PATH = "../Chess Game/Dependencies/";



constexpr float shift = glm::radians(40.0f);
constexpr float clamp_max = glm::radians(90.0f);
constexpr glm::mat4 identity = glm::mat4(1.0f);

#define CHESS_WINDOW_WIDTH 1000
#define CHESS_WINDOW_HEIGHT 1000
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

#endif