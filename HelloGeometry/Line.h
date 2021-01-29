#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
class Line
{
private:
	unsigned int VAO, VBO;
	unsigned int VAO2, VBO2;
	float poinsLengh;
public:
	Line();
	~Line();
	void VerticalDraw();
	void HorizonDraw();
};

