#include <iostream>;
#include "GLFW/glfw3.h"
#include "src/Graphics/Window.h"

using namespace Steel::Graphics;


int main()
{
	if (glfwInit() == GLFW_TRUE)
		std::cout << "GLFW Initialized" << std::endl;
	else
		std::cout << "Failed to init GLFW";

	WindowProps windowProps {"SteelEngine", 920, 760 };

	Window w(windowProps);

	while (true)
	{
		w.Update();
	}

	return 0;
}