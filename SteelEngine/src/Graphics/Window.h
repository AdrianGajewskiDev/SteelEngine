#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include "WindowProps.h"

namespace Steel {
	namespace Graphics {

		class Window {

		public:
			Window(WindowProps& windowProps);
			~Window();

			void Update() const;

			inline int GetWidth() { return m_WindowData.Width; }
			inline int GetHeight() { return m_WindowData.Height; }
		private:
			GLFWwindow* m_Window;
			WindowProps m_WindowData;
		};

	}
}