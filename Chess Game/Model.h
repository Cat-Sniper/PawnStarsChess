#ifndef MODEL_CLASS
#define MODEL_CLASS

#include "Mesh.h"
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

class Model
{
public:
     Model() {}
    Model(char* path)
    {
        loadModel(path);
    }
    void Draw(Shader& shader);
private:
    // model data
    std::vector<Mesh> meshes;
    std::string directory;

    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif
