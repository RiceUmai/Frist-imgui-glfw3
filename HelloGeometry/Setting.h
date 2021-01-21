#pragma once
#include <GLFW/glfw3.h>

class Setting
{
public:
	Setting();
	~Setting();

	static unsigned int SCR_WIDTH;
	static unsigned int SCR_HEIGHT;
	GLFWwindow* window;
private:

};

Setting::Setting()
{
}

Setting::~Setting()
{
}
