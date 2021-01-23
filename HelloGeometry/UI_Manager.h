#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class UI_Manager
{
private:

public:
	UI_Manager(GLFWwindow* window);
	~UI_Manager();

	void Update(float delta);
	void Draw();
};

