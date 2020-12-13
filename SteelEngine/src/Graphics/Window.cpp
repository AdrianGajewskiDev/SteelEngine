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
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			/// <summary>
			/// TODO: Remove
			/// </summary>
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 0);
			glVertex2f(0, 0.5f);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glEnd();


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
			
			glfwMakeContextCurrent(m_Window);


		}
	}

}