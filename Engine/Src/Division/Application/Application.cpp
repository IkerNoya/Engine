#include "dpch.h"

#include "Application.h"
#include "../Events/AppEvent.h"
#include "../Utils/Log.h"

namespace Division 
{
	Application::Application() {

	}
	Application::~Application() {

	}
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)){
			DIV_TRACE(e);
		}
		if(e.IsInCategory(EventCategoryInput)) {
			DIV_TRACE(e);
		}
	}
}
