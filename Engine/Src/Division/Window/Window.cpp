#include "dpch.h"
#include "Window.h"


namespace Division
{
	static bool _GLFWInitialized = false;

	WindowInterface* WindowInterface::Create(const WindowProperties& properties) {
		return new Window(properties);
	}
	
	Window::Window(const WindowProperties& properties) {
		Init(properties);
	}

	Window::~Window() {
		ShutDown();
	}

	void Window::Init(const WindowProperties& properties) {
		_data.title = properties.title;
		_data.width = properties.width;
		_data.height = properties.height;

		DIV_CORE_INFO("Creating Window {0} ({1}, {2})", properties.title, properties.width, properties.height);

		if (!_GLFWInitialized) {
			int success = glfwInit();
			DIV_CORE_ASSERT(success, "Couldn't initialize GLFW");

			_GLFWInitialized = true;
		}
		
		_window = glfwCreateWindow(static_cast<int>(_data.width), static_cast<int>(_data.height), _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);
	}

	void Window::ShutDown() {
		glfwDestroyWindow(_window);
	}

	void Window::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}
	void Window::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		_data.vsync = enabled;
	}
	bool Window::IsVSyncEnabled() const
	{
		return _data.vsync;
	}
}
