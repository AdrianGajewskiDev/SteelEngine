#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace Steel {
	namespace Graphics {

		class Window {

		public:
			Window(const std::string& title = "SteelEngine", int width = 960, int height = 720);
			~Window();

			void Update() const;
			void Close();
			GLFWwindow* GetWindow();
			inline int GetWidth() { return m_Width; }
			inline int GetHeight() { return m_Height; }
		private:
			void CreateWindow();
			GLFWwindow* m_Window;

			int m_Width;
			int m_Height;
			std::string m_Title;
		};

	}
}