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

	Camera camera;

	unsigned int VAO, VBO;

	void processInput(GLFWwindow* window, float deltaTime);

public:
	Game(GLFWwindow* window);
	~Game();
	
	void Update(float delta);
	void Draw();
};


