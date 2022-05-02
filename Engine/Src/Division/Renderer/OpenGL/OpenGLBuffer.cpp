#include "dpch.h"
#include <glad/glad.h>

#include "OpenGLBuffer.h"

namespace Division {
	// Vertex Buffer -------------------------------------------------------------------------------

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, unsigned int size) 
	{
		glCreateBuffers(1, &_renderID);
		glBindBuffer(GL_ARRAY_BUFFER, _renderID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); 
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_renderID);
	}
	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, _renderID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// Index Buffer -------------------------------------------------------------------------------

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indices, unsigned int count)
	{
		glCreateBuffers(1, &_renderID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &_renderID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}
