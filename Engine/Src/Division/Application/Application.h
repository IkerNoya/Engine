#ifndef APP_H
#define APP_H
#include "Division/Core.h"
#include "Division/Events/Event.h"
#include "Division/Events/AppEvent.h"
#include "Division/Window/WindowInterface.h"

namespace Division
{
	//solo hay uno por motor/app
	class DIVISION_API Application
	{
		//unique indica que solo esta clase posee este puntero/instancia
		std::unique_ptr<WindowInterface> _window;
		bool _running = true;
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
	};
	Application* CreateApplication();
}


#endif // !APP_H



