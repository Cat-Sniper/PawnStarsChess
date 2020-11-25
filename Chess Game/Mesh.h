#ifndef MESH_CLASS
#define MESH_CLASS

#include <GL\glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
};

class Mesh {
public:
    // mesh data
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    void Draw(Shader& shader);
private:
    //  render data
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};

#endif
