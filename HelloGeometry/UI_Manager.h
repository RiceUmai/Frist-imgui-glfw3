#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Game.h"

class UI_Manager
{
private:

	float test;

	Game* _game;
public:
	UI_Manager(GLFWwindow* window, Game* game);

	void Update(float delta);
	void Draw();

	float getTest() { return test; }
};

