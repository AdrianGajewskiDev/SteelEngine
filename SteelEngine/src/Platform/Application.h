#pragma once

#include "GLEW/GL/glew.h" 
#include "../Graphics/Window.h"
#include "../GUI/EngineUI.h"


namespace Steel
{
	namespace Platform
	{
		class Application
		{
		public:
			Application();
			Application(Graphics::Window& window);
			~Application();

			void Run();
		private:
			void Init();
			void OnUpdate() const;
			void OnRender() const;
			void OnStartup() const;

		private:
			Graphics::Window* m_Window;
			bool m_Running;
			GUI::EngineUI gui;

		};
	}
}

