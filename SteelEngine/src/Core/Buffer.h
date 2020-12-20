#pragma once
#include "GLEW/GL/glew.h"

namespace Steel
{
	namespace Core
	{
		class Buffer
		{
		protected:
			virtual void Bind(GLsizeiptr size, const void* data) = 0;
			virtual void UnBind() = 0;
			virtual void UnBindVertexAttrib(int index) { };
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
			virtual void AddVertexAttrib(int index, float size, int type, bool normalized, int stride, const void* pointer) { };
			virtual int GetID() = 0;
		};
	}
}