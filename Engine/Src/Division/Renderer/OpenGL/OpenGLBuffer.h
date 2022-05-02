#ifndef OPENGL_BUFFER_H
#define OPENGL_BUFFER_H
#include "Division/Renderer/Buffer.h"

namespace Division {
	
	class DIVISION_API  OpenGLVertexBuffer : public VertexBuffer {
		unsigned int _renderID;

	public:
		OpenGLVertexBuffer(float* vertices, unsigned int size);
		virtual ~OpenGLVertexBuffer() override;

		virtual void Bind() const;
		virtual void Unbind() const;

	};

	class DIVISION_API  OpenGLIndexBuffer : public IndexBuffer {
		unsigned int _renderID;
		unsigned int _count;

	public:
		OpenGLIndexBuffer(unsigned int* indices, unsigned int count);
		virtual ~OpenGLIndexBuffer() override;

		virtual unsigned int GetCount() const { return _count; }

		virtual void Bind() const;
		virtual void Unbind() const;
	};

}


#endif // !OPENGL_BUFFER_H
