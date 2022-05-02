#include "dpch.h"
#include "OpenGLContext.h"
#include "GLFW/glfw3.h"
#include <glad/glad.h>


namespace Division
{

	OpenGLContext::OpenGLContext(GLFWwindow* window)  {
		_window = window;
		DIV_CORE_ASSERT(_window, "Window is null");
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DIV_CORE_ASSERT(status, "Couldn't initialize glad");

		DIV_CORE_INFO("OPENGL INFO");
		DIV_CORE_INFO("  Vecndor: {0}", glGetString(GL_VENDOR));
		DIV_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		DIV_CORE_INFO("  OpenGL Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(_window);
	}

}

