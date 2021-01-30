#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class UI_Manager
{
private:

	glm::vec4 BackGroundColor;
	glm::vec3 cameraPositionText;
	glm::vec3 faceNormalColor;
	float normal_length;
		
public:
	UI_Manager(GLFWwindow* window);
	~UI_Manager();

	void Update(float delta);
	void Draw();

	glm::vec4 getBackGroundColor() { return BackGroundColor; }
	glm::vec3 getfaceNormalColor() { return faceNormalColor; }

	float getnormal_length() { return normal_length; }

	float* getBackGroundColor1();
	

	void SetcameraPositionText(glm::vec3 pos) { cameraPositionText = pos; }
};

