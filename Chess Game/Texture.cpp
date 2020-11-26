#include "Texture.h"
#include <iostream>

Texture::Texture() {
    tID = 0;
    tNum = -1;
}

Texture::Texture(std::string path, int type, int target) {
    tNum = target;
    stbi_set_flip_vertically_on_load(0);
    int imgWidth, imgHeight, imgNrChannels;
    unsigned char* data = stbi_load(path.c_str(), &imgWidth, &imgHeight, &imgNrChannels, 0);

	glGenTextures(1, &tID);
    glActiveTexture(GL_TEXTURE0 + target);
    glBindTexture(GL_TEXTURE_2D, tID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, type, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

Texture::~Texture() {

}

void Texture::Bind(int texNum) {
    if (tNum == -1) {
        glActiveTexture(GL_TEXTURE0 + texNum);
        glBindTexture(GL_TEXTURE_2D, tID);
        tNum = texNum;
    }
    else {
        std::cout << "Tried to bind already bound texture. Don't do that.\n";
    }
}

void Texture::Unbind() {
    if (tNum == -1) {
        std::cout << "Texture is not currently bound. Can't unbind.\n";
    }
    else {
        glActiveTexture(GL_TEXTURE0 + tNum);
        glBindTexture(GL_TEXTURE_2D, 0);
        tNum = -1;
    }
}

int Texture::getTID() { return tID; }
int Texture::getTNum() { return tNum; }
bool Texture::bound() { return (tNum == -1) ? false : true; }