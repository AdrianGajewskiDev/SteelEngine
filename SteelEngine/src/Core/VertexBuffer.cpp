#include "VertexBuffer.h"

namespace Steel
{
	namespace Core
	{
		VertexBuffer::VertexBuffer(GLenum usage)
			: m_Usage(usage)
		{ }

		void VertexBuffer::Bind(GLsizeiptr size, const void* data)
		{
			glGenBuffers(1, &m_ID);
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
			glBufferData(GL_ARRAY_BUFFER, size, data, m_Usage);
		}

		void VertexBuffer::UnBind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void VertexBuffer::UnBindVertexAttrib(int index)
		{
			glDisableVertexAttribArray(index);
		}

		void VertexBuffer::AddVertexAttrib(int index, float size, int type, bool normalized, int stride, const void* pointer)
		{
			glVertexAttribPointer(index, size, type, normalized, stride, pointer);
			glEnableVertexAttribArray(index);
			auto i = glGetError();

		}

		int VertexBuffer::GetID()
		{
			return m_ID;
		}


	}
}