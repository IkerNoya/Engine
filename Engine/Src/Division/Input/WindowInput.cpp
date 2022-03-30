#include "dpch.h"
#include "WindowInput.h"
#include "Division/Application/Application.h"
#include <GLFW/glfw3.h>

namespace Division
{
	Input* Input::_instance = new WindowInput();

	bool WindowInput::IsKeyPressed_Implementation(int keycode){
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowInput::IsMouseButtonPressed_Implementation(int button){
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	float WindowInput::GetMouseX_Implementation(){
		auto[x,y] = GetMousePosition_Implementation();

		return static_cast<float>(x);
	}

	float WindowInput::GetMouseY_Implementation(){
		auto [x, y] = GetMousePosition_Implementation();

		return static_cast<float>(y);
	}

	std::pair<float, float> WindowInput::GetMousePosition_Implementation()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x;
		double y;

		glfwGetCursorPos(window, &x, &y);

		return { static_cast<float>(x), static_cast<float>(y) };
	}
}

