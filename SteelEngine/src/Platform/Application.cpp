#include "Application.h";
#include "../Graphics/Window.h"
#include "../Shaders/Shader.h"
#include "../Log.h"
#include "../File/FileLoader.h"
#include <random>
#include <time.h>


#define FRAME_TIME 16.6f

namespace Steel
{

	namespace Platform
	{
		Application::Application()
			:m_Running(true)
		{
			Init();
			m_Window = new Graphics::Window();
			glewExperimental = GL_TRUE;
			glewInit();
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
				LOG("Failed to initialize GLFW", LOG_ERROR);

				m_Window->Close();
				glfwTerminate();
				m_Running = false;
				return;
			}
		}

		void Application::OnUpdate() const
		{
			float colors[3] = { 0.0f, 0.0f, 0.0f };

			srand((unsigned)time(NULL));

			for (int i = 0; i < 3; i++)
			{
				colors[i] = (float)rand() / RAND_MAX;
			}

			int program;
			glGetIntegerv(GL_CURRENT_PROGRAM, &program);

			int location = glGetUniformLocation(program, "m_Color");
			glUniform3f(location, colors[0], colors[1], colors[2]);
		}


		void Application::OnRender() const
		{
			glClearColor(59.0f / 255.0f, 59.0f / 255.0f, 59.0f / 255.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_QUAD_STRIP, 0, 4);

			m_Window->Update();
		}

		void Application::OnStartup() const
		{
			LOG("StartingUp", LOG_INFORMATION);

			float positions[8] =
			{
				0.5f, 0.5f,		
				-0.5f,0.5f,		
				0.5f, -0.5f,	
				-0.5f, -0.5f	
			};

			unsigned int vao;
			glGenBuffers(1, &vao);
			glBindBuffer(GL_ARRAY_BUFFER, vao);
			glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 2, GL_FLOAT, false, 8, 0);

			glEnableVertexAttribArray(0);

			std::string vertexShader = FileLoader::READFROMTXT("src/Shaders/shaders/VertexShader.glsl");
			std::string fragmentShader = FileLoader::READFROMTXT("src/Shaders/shaders/FragmentShader.glsl");

			unsigned int program = glCreateProgram();

			Shaders::Shader shader(vertexShader, fragmentShader, &program);
			shader.Create();

			glUseProgram(program);
		}
	}
}
