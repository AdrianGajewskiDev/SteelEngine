#pragma once 
#include "Buffer.h"
#include "GLEW/GL/glew.h"


namespace Steel
{
	namespace Core
	{
		class VertexBuffer : public Buffer
		{
		public:
			VertexBuffer(GLenum usage);
			void Bind(GLsizeiptr size, const void* data) override;
			void UnBind() override;
			void UnBindVertexAttrib(int index) override;
			int GetID() override;
			void AddVertexAttrib(int index, float size, int type, bool normalized, int stride, const void* pointer) override;
		private:
			GLenum m_Usage;
			unsigned int m_ID;
		};
	}
}