#include "dpch.h"
#include "Window.h"
#include "Division/Events/AppEvent.h"
#include "Division/Events/KeyEvent.h"
#include "Division/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Division
{
	static bool _GLFWInitialized = false;

	static void GLFWErorCallback(int error, const char* description) {
		DIV_CORE_ERROR("GLFW Error {0}: {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErorCallback);
			_GLFWInitialized = true;
		}

		_window = glfwCreateWindow(static_cast<int>(_data.width), static_cast<int>(_data.height), _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DIV_CORE_ASSERT(status, "Couldn't initialize glad");
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);

		SetCallbacks();
	}

	void Window::ShutDown() {
		glfwDestroyWindow(_window);
	}

	void Window::SetCallbacks()
	{
		//Set callbacks
		glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;

				WindowResizeEvent resizeEvent(width, height);
				data.EventCallback(resizeEvent);
			});
		glfwSetWindowCloseCallback(_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent closeEvent;
				data.EventCallback(closeEvent);
			});

		glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action) {
					case GLFW_RELEASE:
					{
						KeyReleasedEvent keyReleaseEvent(key);
						data.EventCallback(keyReleaseEvent);
						break;
					}
					case GLFW_PRESS:
					{
						KeyPressedEvent keyPressEvent(key, 0);
						data.EventCallback(keyPressEvent);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent keyPressedEvent(key, 1);
						data.EventCallback(keyPressedEvent);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent pressCallback(button);
					data.EventCallback(pressCallback);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent releaseCallback(button);
					data.EventCallback(releaseCallback);
					break;
				}
			}
			});

		glfwSetScrollCallback(_window, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent scrollEvent(static_cast<float>(x), static_cast<float>(y));
			data.EventCallback(scrollEvent);
			});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent movedEvent(static_cast<float>(x), static_cast<float>(y));
			data.EventCallback(movedEvent);
			});
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
