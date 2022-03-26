#ifndef APP_EVENT_H
#define APP_EVENT_H

#include "Event.h"

namespace Division
{
	class DIVISION_API WindowResizeEvent : public Event {
		unsigned int _width;
		unsigned int _height;
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : _width(width), _height(height) {}
		inline unsigned int GetWidth() const { return _width; }
		inline unsigned int GetHeight() const { return _height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _width << " , " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DIVISION_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DIVISION_API TickEvent : public Event {
	public:
		TickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DIVISION_API UpdateEvent : public Event {
	public:
		UpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DIVISION_API RenderEvent : public Event {
	public:
		RenderEvent() {}

		EVENT_CLASS_TYPE(AppRenderer)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


}

#endif // !APP_EVENT_H
