#include "Shader.h"

void Shader::readFile(std::string filename, std::string& rtrn) {
    std::string line;
    std::ifstream myfile(filename);
    getline(myfile, rtrn);
    rtrn += '\n';
    while (getline(myfile, line)) {
        rtrn += line;
    }
}

unsigned int Shader::getID() { return shaderProgramID; }

void Shader::bind() const {
    glUseProgram(shaderProgramID);
}

void Shader::unbind() const {
    glUseProgram(0);
}

void Shader::setMat4Uniform(std::string uniname, const GLfloat* value) {
    int uniLoc = glGetUniformLocation(shaderProgramID, uniname.c_str());
    glUniformMatrix4fv(uniLoc, 1, GL_FALSE, value);
} 

void Shader::setIntUniform(std::string uniname, GLint value) {
    int uniLoc = glGetUniformLocation(shaderProgramID, uniname.c_str());
    glUniform1i(uniLoc, value);
}

void Shader::setVec3Uniform(std::string uniname, const GLfloat* value) {
    int uniLoc = glGetUniformLocation(shaderProgramID, uniname.c_str());
    glUniform3fv(uniLoc, 1, value);
}



Shader::Shader(std::string vShaderPath, std::string fShaderPath) {
    

    std::string vShader, fShader;
    readFile(vShaderPath, vShader);
    readFile(fShaderPath, fShader);
    const char* vShaderSource = vShader.c_str();
    const char* fShaderSource = fShader.c_str();

    //Compiling shaders
    int success;
    char infolog[512];
    int vShaderID, fShaderID;

    vShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShaderID, 1, &vShaderSource, NULL);
    glCompileShader(vShaderID);
    glGetShaderiv(vShaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vShaderID, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
    }

    fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShaderID, 1, &fShaderSource, NULL);
    glCompileShader(fShaderID);
    glGetShaderiv(fShaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fShaderID, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl;
    }
    
    shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vShaderID);
    glAttachShader(shaderProgramID, fShaderID);
    glLinkProgram(shaderProgramID);
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::LINKING::FAILED\n" << infolog << std::endl;
    }
    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);

}