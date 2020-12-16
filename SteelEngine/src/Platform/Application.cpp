#include "Application.h";
#include "../Log.h";


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

			/// <summary>
			/// Stride, offset between each vertex eq:  
			/// float positions[8] =
			/// {
				///200.0f, 100.0f,
				///500.0f, 100.0f,
				///200.0f, 400.0f,
				///500.0f, 400.0f
			/// };
			/// will be 8 because float takes 4 bytes
			/// </summary>
			/// pointer, specify how many bytes to reach a vertex attribute
			/// eq: 1,2,5,5,1,5,5, (2pos, 2tex, 3uv), so to get tex values we have to "skip" 8 bytes (2 floats * 4) 

			glVertexAttribPointer(0, 2, GL_FLOAT, false, 8, 0);
			glEnableVertexAttribArray(0);


			std::string vertexShader =
				"#version 330 core\n"
				"\n"
				"layout(location = 0) in vec4 position;"
				"\n"
				"void main()\n"
				"{\n"
					"gl_Position = position;\n"
				"}";

			std::string fragmentShader =
				"#version 330 core\n"
				"\n"
				"layout(location = 0) out vec4 color;"
				"\n"
				"void main()\n"
				"{\n"
				"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
				"}";

			unsigned int program = glCreateProgram();

			Shaders::Shader shader(vertexShader, fragmentShader, program);

			LOG(std::to_string(program), LOG_DEBUG);

			int prograam;
			glGetIntegerv(GL_CURRENT_PROGRAM, &prograam);

			LOG(std::to_string(program), LOG_DEBUG);

			glUseProgram(program);
		}
	}
}
