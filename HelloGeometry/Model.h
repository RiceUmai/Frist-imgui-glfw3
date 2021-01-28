#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include "Shader.h"
#include "Mesh.h"

class Model
{
public:
	Model(std::string const &path, bool gamma =false) { loadModel(path); };
	
	void SetPosition(glm::vec3 pos) { Position = pos; }
	void SetAngle(float angle) { Angle = angle; }
	void SetRotDir(glm::vec3 rot) { RotDir = rot; }
	void SetScale(glm::vec3 scale) { Scale = scale; }

	glm::vec3 GetPosition() { return Position; }
	glm::vec3 GetRotation() { return RotDir; }
	glm::vec3 GetScale() { return Scale; }

	void Draw(Shader shader);
	void Draw(Shader shader, glm::mat4 projection, glm::mat4 view);
private:
	glm::vec3 Position = glm::vec3(0, 0, 0);
	glm::vec3 RotDir = glm::vec3(0, 0, 0);
	glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	float Angle = 0;


	std::vector<Mesh> meshes;
	std::vector<Texture> textures_loaded;
	std::string directory;

	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *sceme);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string &directory, bool gamma = false);
};

