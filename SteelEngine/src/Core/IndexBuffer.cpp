#include "IndexBuffer.h"

namespace Steel
{
	namespace Core
	{
		IndexBuffer::IndexBuffer(GLenum usage)
			: m_Usage(usage)
		{ }

		void IndexBuffer::Bind(GLsizeiptr size, const void* data)
		{
			glGenBuffers(1, &m_ID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, m_Usage);
		}

		void IndexBuffer::UnBind()
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		int IndexBuffer::GetID()
		{
			return m_ID;
		}


	}
}