#pragma once

#ifndef SHADER_ABSTRACTION
#define SHADER_ABSTRACTION
#include <GL\glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {

private:
    unsigned int shaderProgramID;
    

    void readFile(std::string filename, std::string& rtrn);

public:
    Shader(std::string vShaderPath, std::string fShaderPath);
    unsigned int getID();
    void bind() const;
    void unbind() const;
    void setMat4Uniform(std::string uniname, const GLfloat* value);
    void setIntUniform(std::string uniname, GLint value);
    void setVec3Uniform(std::string uniname, const GLfloat* value);
    
};

#endif
