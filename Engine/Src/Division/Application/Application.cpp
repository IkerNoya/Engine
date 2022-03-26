#include "dpch.h"

#include "Application.h"
#include "../Events/AppEvent.h"
#include "../Utils/Log.h"
#include "GLFW/glfw3.h"

namespace Division 
{
	Application::Application() {
		//no lo tenemos que eliminar manualmente
		_window = std::unique_ptr<WindowInterface>(WindowInterface::Create());
	}
	Application::~Application() {
	}
	void Application::Run() {
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->OnUpdate();
		}
	}
}
