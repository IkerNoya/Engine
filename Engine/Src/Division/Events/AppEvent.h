#ifndef APP_EVENT_H
#define APP_EVENT_H

#include "Event.h"
#include <sstream>

namespace Division
{
	class DIVISION_API WindowResizeEvent : public Event {
		unsigned int _width; 
		unsigned int _height;
	public: 
		WindowResizeEvent(unsigned int width, unsigned int height) : _width(width), _height(height){}
		inline unsigned int GetWidth() const { return _width; }
		inline unsigned int GetHeight() const { return _height; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _width << " , " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}

#endif // !APP_EVENT_H
