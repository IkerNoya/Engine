#include "dpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Division/Renderer/OpenGL/OpenGLBuffer.h"

namespace Division {



	VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:  DIV_CORE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;

		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}
		DIV_CORE_ASSERT(false, "Unknown render API");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(unsigned int* indices, unsigned int count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:  DIV_CORE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;

		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, count);
		}
		DIV_CORE_ASSERT(false, "Unknown render API");
		return nullptr;
	}

}