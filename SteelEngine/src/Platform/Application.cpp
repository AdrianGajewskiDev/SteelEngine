#include "Application.h";
#include "../Log.h"

namespace Steel
{
	namespace Platform
	{
		Application::Application()
			:m_Running(true)
		{
			Init();
			m_Window = new Graphics::Window();
			OnStartup();

		}

		Application::Application(Graphics::Window& window)
			: m_Running(true)
		{
			m_Window = &window;
		}

		Application::~Application()
		{
			delete m_Window;
		}

		void Application::Run()
		{
			while (m_Running)
			{
				OnUpdate();
				OnRender();
			}
		}

		void Application::Init()
		{
			if (glfwInit() != GL_TRUE)
			{
				m_Window->Close();
				glfwTerminate();
				m_Running = false;
				return;
			}

		}

		void Application::OnUpdate() const
		{
			LOG("Updating", LOG_INFORMATION);

			(*m_Window).Update();
			glfwPollEvents();
			glfwSwapBuffers(m_Window->GetWindow());
		}


		void Application::OnRender() const
		{
			LOG("Rendering", LOG_WARNING);
		}

		void Application::OnStartup() const
		{
			LOG("StartingUp", LOG_ERROR);
		}
	}
}