#include "dpch.h"

#include "Application.h"

#include "Division/Utils/Log.h"
#include <glad/glad.h>

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
			glClearColor(.37f, .36f, .64f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _layerStack) {
				layer->OnUpdate();
			}

			_window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e){
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(OnWindowClosed));

		for (auto it = _layerStack.end(); it != _layerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled())
				break;
		}

	}
	void Application::PushLayer(Layer* layer){
		_layerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* overlay){
		_layerStack.PushOverlay(overlay);
	}
	bool Application::OnWindowClosed(WindowCloseEvent& e){
		_running = false;
		return true;
	}
}
