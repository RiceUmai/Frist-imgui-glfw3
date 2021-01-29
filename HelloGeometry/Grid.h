#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#include "Line.h"


class Grid
{
private:
	unsigned int VAO, VBO;
	Line line;

	glm::vec3 Position;
	int Column;
	int Row;

public:
	Grid(int column, int row);
	~Grid();
	void Draw(Shader shader, glm::mat4 projection, glm::mat4 view);

	void setPosition(glm::vec3 pos) { Position = pos; }
};

