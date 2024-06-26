﻿#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#include "Model.h"
#include "Camera.h"

#include "Grid.h";
#include "Setting.h"
#include "UI_Manager.h"

class Game
{
private:
	GLFWwindow* _window;

	Model TeaPort;
	Model Cube;
	Model Sphere;
	Model Bunny;
	
	Grid grid;

	Shader modelShader;
	Shader explodeShader;
	Shader Thorn;
	Shader faceNormal;
	Shader gridShader;

	Camera camera;

	glm::vec3 RotatDir = glm::vec3(0,0,0);
	glm::vec3 Color = glm::vec3(0,0,0);
	
	UI_Manager* UI;

	float Speed = 0;
	
	float _lastX = Setting::SCR_WIDTH;
	float _lastY = Setting::SCR_HEIGHT;
	
	bool firstMouse = true;

	void processInput(GLFWwindow* window, float deltaTime);

public:
	Game(GLFWwindow* window, UI_Manager* ui);
	~Game();


	void Update(float delta);
	void Draw();

	float GettestFloat() { return Speed; }

	void SettestFloat(float variable) { Speed = variable; }
	void SetRotatDir(glm::vec3 variable) { RotatDir = variable; }
	void SetColor(glm::vec3 color) { Color = color; }

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};


