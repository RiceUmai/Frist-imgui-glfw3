#include "Game.h"


Game::Game(GLFWwindow* window, UI_Manager* ui) : //ui_Manager(window),
	Cube("model/cube.obj"),
	Sphere("model/sphere.obj"),
	TeaPort("model/newell_teaset/teapot.obj"),
	Bunny("model/bunny.obj"),
	modelShader("Shader/model_loading.vs", "Shader/model_loading.fs"),
	explodeShader("Shader/model_loading.vs", "Shader/model_loading.fs", "Shader/explode.gs"),
	Thorn("Shader/model_loading.vs", "Shader/model_loading.fs", "Shader/Thorn.gs"),
	faceNormal("Shader/model_loading.vs", "Shader/faceNormal.fs", "Shader/faceNormal.gs"),
	gridShader("Shader/grid.vs", "Shader/grid.fs"),
	grid(100, 100),
	camera(glm::vec3(0.0f, 0.0f, 13.0f))
{

	_window = window;
	grid.setPosition(glm::vec3(0, -2.0f, 0));
	UI = ui;
}

Game::~Game()
{
}

void Game::Update(float delta)
{
	processInput(_window, delta);
}

void Game::Draw()
{
	//==================================
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)Setting::SCR_WIDTH / (float)Setting::SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	//==================================
	UI->SetcameraPositionText(camera.Position);

	modelShader.use();
	modelShader.setFloat("time", (float)glfwGetTime());

	//TeaPort Obje
	//==================================
	TeaPort.SetPosition(glm::vec3(0, -1.0f, 0));
	TeaPort.SetAngle((float)glfwGetTime() * 20);
	TeaPort.SetRotDir(glm::vec3(0, 1, 0));
	TeaPort.Draw(modelShader, projection, view);
	//==================================

	//Cube Object
	//==================================
	Cube.SetPosition(glm::vec3(10.0f, 0.0f, 0.0f));
	Cube.Draw(modelShader, projection, view);

	//Sphere Object
	//==================================
	Sphere.SetPosition(glm::vec3(20.0f, 0.0f, 0));
	Sphere.Draw(modelShader, projection, view);

	Thorn.use();
	Thorn.setFloat("time", (float)glfwGetTime());
	Sphere.SetPosition(glm::vec3(20.0f, 5.0f, 0));
	Sphere.Draw(Thorn, projection, view);
	//==================================

	//Bunny Object
	//==================================
	Bunny.SetPosition(glm::vec3(-10.0f, 0, 0));	
	Bunny.SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
	Bunny.Draw(modelShader, projection, view);

	Bunny.SetPosition(glm::vec3(-30.0f, 0, 0));
	Bunny.SetScale(glm::vec3(3.0f, 3.0f, 3.0f));
	Bunny.Draw(modelShader, projection, view);

	explodeShader.use();
	explodeShader.setFloat("time", (float)glfwGetTime());
	Bunny.SetPosition(glm::vec3(-10.0f, 5.0f, 0.0f));
	Bunny.SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
	Bunny.Draw(explodeShader, projection, view);

	faceNormal.use();
	faceNormal.setFloat("time", (float)glfwGetTime());
	faceNormal.setVec3("Color", UI->getfaceNormalColor());
	faceNormal.setFloat("normal_length", UI->getnormal_length());
	Bunny.SetPosition(glm::vec3(-20.0f, -0.0f, 0.0f));
	Bunny.SetScale(glm::vec3(3.0f, 3.0f, 3.0f));
	Bunny.Draw(faceNormal, projection, view);
	//==================================
	
	grid.Draw(gridShader, projection, view);
}

void Game::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
	{
		float xoffset = xpos - _lastX;
		float yoffset = _lastY - ypos;

		this->camera.ProcessMouseMovement(xoffset, yoffset);
	}
	_lastX = xpos;
	_lastY = ypos;
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

	//Program Close======================================
	//===================================================
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);



	//Camera Movement====================================
	//===================================================
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}