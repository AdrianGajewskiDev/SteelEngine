#include "Window.h"


namespace Steel {
	namespace Graphics {
		Window::Window(const std::string& title,  int width,  int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			CreateWindow();
		}

		Window::~Window()
		{
			delete m_Window;
		}

		void Window::Update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		void Window::Close()
		{
			glfwDestroyWindow(m_Window);
		}

		GLFWwindow* Window::GetWindow()
		{
			if(m_Window)
				return m_Window;

			return nullptr;
		}

		void Window::CreateWindow()
		{
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
					glfwDestroyWindow(window);
					glfwTerminate();
			});
			glfwMakeContextCurrent(m_Window);

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		}
	}

}