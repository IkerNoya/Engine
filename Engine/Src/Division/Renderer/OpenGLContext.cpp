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
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(_window);
	}

}

