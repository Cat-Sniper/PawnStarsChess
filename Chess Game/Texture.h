#pragma once

//Make sure you don't shift textures around to different targets, bad things can happen with the current version. There are 32 units so you won't run out

#ifndef TEXTURE
#define TEXTURE
#include <GL\glew.h>
#include <stb_image.h>
#include <string>

class Texture {
private:
	unsigned int tID;
	int tNum;
public:
	Texture();

	Texture(std::string path, int type, int target);
	~Texture();

	void Bind(int texNum);
	void Unbind();
	int getTID();
	int getTNum();
	bool bound();
};
	
#endif