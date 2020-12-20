#include "Application.h"
#include "../Graphics/Window.h"
#include "../Shaders/Shader.h"
#include "../Log.h"
#include "../File/FileLoader.h"
#include "../Core/VertexBuffer.h"
#include "../Core/IndexBuffer.h"


namespace Steel
{

	namespace Platform
	{
		Application::Application()
			: m_Running(true),
			gui()
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
			/// <summary>
			/// TODO: add fps limit
			/// </summary>
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
			gui.UpdateUI();
		}


		unsigned int indices[6] =
		{
			0,1,2,
			1,3,2
		};

		void Application::OnRender() const
		{
			glClearColor(59.0f / 255.0f, 59.0f / 255.0f, 59.0f / 255.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			m_Window->Update();
		}

		void Application::OnStartup() const
		{
			LOG("StartingUp", LOG_INFORMATION);

			gui.Init();

			float positions[8] =
			{
				0.5f, 0.5f,	 //0	
				-0.5f,0.5f,	 //1	
				0.5f, -0.5f, //2	
				-0.5f, -0.5f //3	
			};


			Core::VertexBuffer vbo(GL_STATIC_DRAW);
			vbo.Bind(sizeof(positions), positions);
			vbo.AddVertexAttrib(0, 2, GL_FLOAT, false, 8, 0);

			Core::IndexBuffer ibo(GL_STATIC_DRAW);

			std::string vertexShader = FileLoader::READFROMTXT("src/Shaders/shaders/VertexShader.glsl");
			std::string fragmentShader = FileLoader::READFROMTXT("src/Shaders/shaders/FragmentShader.glsl");

			unsigned int program = glCreateProgram();

			Shaders::Shader shader(vertexShader, fragmentShader, &program);
			shader.Create();
			glUseProgram(program);

			shader.SetUniform3f("m_Color", 0.0f, 0.4f, 0.0f);
		}
	}
}
