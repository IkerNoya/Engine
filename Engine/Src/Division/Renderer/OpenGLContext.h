#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H
#include "Division/Core.h"
#include "RendererContext.h"

struct GLFWwindow;
namespace Division 
{
	class DIVISION_API OpenGLContext : public RendererContext {
		GLFWwindow* _window;

	public:
		OpenGLContext(GLFWwindow* window);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	};
}


#endif // !OPENGL_CONTEXT_H


