#pragma once 
#include <string>
#include <GLFW\glfw3.h>


namespace Steel
{
	namespace GUI
	{

		class EngineUI
		{
		public:
			EngineUI() = default;
			~EngineUI();
		public:
			void AddWindow(const std::string& title);
			void Init() const;
			void UpdateUI() const;
		private:
		};
	}
}