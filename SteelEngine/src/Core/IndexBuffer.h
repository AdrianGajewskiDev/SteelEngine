#pragma once
#include "Buffer.h"
#include "GLEW/GL/glew.h"

namespace Steel
{
	namespace Core
	{
		class IndexBuffer : public Buffer
		{
		public:
			IndexBuffer(GLenum usage);
			void Bind(GLsizeiptr size, const void* data) override;
			void UnBind() override;
			int GetID() override;
		private:
			GLenum m_Usage;
			unsigned int m_ID;
		};
	}
}