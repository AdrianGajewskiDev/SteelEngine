#pragma once
#include "GLEW/GL/glew.h"
#include <string>
#include <iostream>


namespace Steel
{
	namespace Shaders
	{
		class Shader
		{
			
		public:
			Shader(const std::string& vertexShaderSource, const std::string& fragmentaderSource, unsigned int* program);
			void Create();
		private:
			unsigned int Compile(unsigned int type);
		private:
			 std::string m_VertexShaderSource;
			 std::string m_FragmentShaderSource;
			 unsigned int m_Program;
		};
	}
}