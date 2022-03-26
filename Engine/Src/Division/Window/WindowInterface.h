#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H

#include "dpch.h"
#include "Division/Core.h"
#include "Division/Events/Event.h"

namespace Division
{
	struct WindowProperties {
		std::string title;
		unsigned int width;
		unsigned int height;
		WindowProperties(const std::string& newTitle = "Division", unsigned int newWidth = 1280, unsigned int newHeight = 720) :
																											title(newTitle), width(newWidth), height(newHeight) {}
	};

	class DIVISION_API WindowInterface{
	public:
		static WindowInterface* Create(const WindowProperties& properties = WindowProperties());

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~WindowInterface() {}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;
	};
}


#endif // !WINDOW_INTERFACE_H


