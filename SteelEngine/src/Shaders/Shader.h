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
			void SetUniform4f(const char* name, float v1, float v2, float v3, float v4);
			void SetUniform3f(const char* name, float v1, float v2, float v3);
		private:
			unsigned int Compile(unsigned int type);
		private:
			 std::string m_VertexShaderSource;
			 std::string m_FragmentShaderSource;
			 unsigned int m_Program;
		};
	}
}