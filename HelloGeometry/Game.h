#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Setting.h"

class Game
{
private:
	GLFWwindow* _window;

	Model modeltest;
	Shader modelShader;
	Shader testShader;

	unsigned int VAO, VBO;

	glm::vec3 RotatDir = glm::vec3(0,0,0);
	glm::vec3 Color = glm::vec3(0,0,0);
	
	float Speed = 0;
	
	void processInput(GLFWwindow* window, float deltaTime);

public:
	Game(GLFWwindow* window);
	~Game();

	Camera camera;

	void Update(float delta);
	void Draw();

	float GettestFloat() { return Speed; }

	void SettestFloat(float variable) { Speed = variable; }
	void SetRotatDir(glm::vec3 variable) { RotatDir = variable; }
	void SetColor(glm::vec3 color) { Color = color; }
};


