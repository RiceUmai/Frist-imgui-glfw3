#include "Grid.h"

Grid::Grid(int column, int row) : line(), Column(column), Row(row), Position(glm::vec3(0))
{

}

Grid::~Grid()
{
}

void Grid::Draw(Shader shader, glm::mat4 projection, glm::mat4 view)
{
	shader.use();
	shader.setMat4("projection", projection);
	shader.setMat4("view", view);;
	for (int i = 0; i < Column; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(Position.x + i - (Column/2), Position.y, Position.z));
		model = glm::scale(model, glm::vec3(Column));
		shader.setMat4("model", model);
		line.Draw();
	}


	for (int i = 0; i < Row; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(Position.x, Position.y, Position.z + i - (Row / 2)));
		model = glm::rotate(model, glm::radians(90.0f) ,glm::vec3(0,1,0));
		model = glm::scale(model, glm::vec3(Row));
		shader.setMat4("model", model);
		line.Draw();
	}
}
