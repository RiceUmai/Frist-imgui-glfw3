#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>

#include "Game.h"
#include "UI_Manager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void Renderer();

float FristTime;
float delta;

Game* game;

//
GLFWwindow* window;
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	// --------------------
	window = glfwCreateWindow(Setting::SCR_WIDTH, Setting::SCR_HEIGHT, "Hellow Grmotry", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glEnable(GL_DEPTH_TEST);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	
	// render loop
	// -----------
	Renderer();
	
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

void Renderer()
{
	//=========================
	UI_Manager* ui_Manager = new UI_Manager(window);
	game = new Game(window, ui_Manager);
	//=========================


	while (!glfwWindowShouldClose(window))
	{
		glm::vec4 vec(ui_Manager->getBackGroundColor());
		float* data = glm::value_ptr(vec);
		glClearColor(data[0], data[1], data[2], data[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		FristTime = glfwGetTime();

		//GameScene Renderer
		//==========================
		game->Update(delta);
		ui_Manager->Update(delta);
		
		game->Draw();
		ui_Manager->Draw();
		//==========================

		glfwSwapBuffers(window);
		glfwPollEvents();
		delta = glfwGetTime() -FristTime;
	}
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	game->mouse_button_callback(window, button, action, mods);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	game->cursor_position_callback(window, xpos, ypos);
}