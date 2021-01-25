#include "Game.h"
#include "UI_Manager.h"

Game::Game(GLFWwindow* window) : //ui_Manager(window),
				Cube("model/cube.obj"),
				Sphere("model/sphere.obj"),
				modeltest("model/newell_teaset/teapot.obj"),
				Bunny("model/bunny.obj"),
				modelShader("Shader/model_loading.vs", "Shader/model_loading.fs", "Shader/Thorn.gs"), 
				testShader("Shader/test.vs", "Shader/test.fs", "Shader/test.gs"),
				camera(glm::vec3(0.0f, 0.0f, 13.0f))
{

	_window = window;
	float poins[] = {
		-0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(poins), &poins, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

}

Game::~Game()
{
}

void Game::Update(float delta)
{
	processInput(_window, delta);

	//glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)Setting::SCR_WIDTH / (float)Setting::SCR_HEIGHT, 0.1f, 100.0f);
	//glm::mat4 view = camera.GetViewMatrix();

	////==================================
	//modelShader.use();
	//modelShader.setMat4("projection", projection);
	//modelShader.setMat4("view", view);
	//modelShader.setVec3("Color", Color);

	//glm::mat4 model = glm::mat4(1.0f);
	//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	////model = glm::rotate(model, glm::radians(90.0f), camera.Right);
	//model = glm::rotate(model, glm::radians((float)glfwGetTime() * 10), RotatDir);
	//model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	//modelShader.setMat4("model", model);
	////modelShader.setFloat("time", glfwGetTime() * Speed);
	////modelShader.setFloat("time", glfwGetTime());
	////==================================
	//model = glm::mat4(1.0f);
	//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	//model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	//modelShader.setMat4("model", model);
}

void Game::Draw()
{
	//==================================
	//glBindVertexArray(VAO);
	//testShader.use();
	//glDrawArrays(GL_POINTS, 0, 4);
	//==================================
	//==================================
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)Setting::SCR_WIDTH / (float)Setting::SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	//modelShader.use();
	//modelShader.setMat4("projection", projection);
	//modelShader.setMat4("view", view);
	//modelShader.setVec3("Color", Color);
	//==================================
	modeltest.Draw(modelShader,projection, view);
	//==================================
	Cube.SetPosition(glm::vec3(10.0f, 0, 0));
	Cube.Draw(modelShader, projection, view);

	modelShader.use();
	modelShader.setFloat("time", (float)glfwGetTime());
	Sphere.SetPosition(glm::vec3(20.0f, 0, 0));
	Sphere.Draw(modelShader, projection, view);

	Bunny.SetPosition(glm::vec3(-10.0f, 0, 0));
	Bunny.Draw(modelShader, projection, view);
}

void Game::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		_lastX = xpos;
		_lastY = ypos;
		firstMouse = false;
	}

	if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
	{
		float xoffset = xpos - _lastX;
		float yoffset = _lastY - ypos;

		_lastX = xpos;
		_lastY = ypos;

		this->camera.ProcessMouseMovement(xoffset, yoffset);
	}



	if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL)
	{
		firstMouse = true;
	}
}

void Game::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
}

void Game::processInput(GLFWwindow* window, float deltaTime)
{

	//===================================================
	//===================================================

	//===================================================
	//===================================================
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}