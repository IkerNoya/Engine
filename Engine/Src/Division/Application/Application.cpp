#include "dpch.h"

#include "Application.h"

#include "Division/Utils/Log.h"
#include "GLFW/glfw3.h"

namespace Division 
{
#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		//no lo tenemos que eliminar manualmente
		_window = std::unique_ptr<WindowInterface>(WindowInterface::Create());
		_window->SetEventCallback(BIND_EVENT(OnEvent));
	}
	Application::~Application() {
	}
	void Application::Run() {
		while (_running) {
			_window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(OnWindowClosed));

		DIV_CORE_TRACE("{0}", e);
	}
	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		_running = false;
		return true;
	}
}
