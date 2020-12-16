#include "GLEW/GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>;
#include "src/Graphics/Window.h"
#include "src/Platform/Application.h"


using namespace Steel::Graphics;


int main()
{
	Steel::Platform::Application application;

	application.Run();

	delete &application;

	return 0;
}