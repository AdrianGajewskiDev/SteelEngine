#include "Window.h"


namespace Steel {
	namespace Graphics {
		Window::Window(WindowProps& windowProps)
			: m_WindowData(windowProps)
		{

			m_Window = glfwCreateWindow(m_WindowData.Width, m_WindowData.Height, m_WindowData.Title.c_str(), NULL, NULL);
			glfwMakeContextCurrent(m_Window);
		}

		Window::~Window()
		{
			delete m_Window;
		}

		void Window::Update() const
		{
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);
			glVertex2f(0, 0.5f);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glEnd();

			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
	}

}