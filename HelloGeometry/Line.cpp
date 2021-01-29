#include "Line.h"

Line::Line()
{
	float VerticalLine[] = {
	0.0f , 0.0f,  -0.5f,
	0.0f , 0.0f,  0.5f,
	};

	float HorizonLine[] = {
	-0.5f , 0.0f,  0.0f,
	0.5f , 0.0f,  0.0f,
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VerticalLine), &VerticalLine, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glBindVertexArray(0);

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(HorizonLine), &HorizonLine, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glBindVertexArray(0);
}

Line::~Line()
{
}

void Line::HorizonDraw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINES, 0, 2);
	glBindVertexArray(0);
}

void Line::VerticalDraw()
{
	glBindVertexArray(VAO2);
	glDrawArrays(GL_LINES, 0, 2);
	glBindVertexArray(0);
}
