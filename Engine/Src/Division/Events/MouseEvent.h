#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H


#include "Event.h"

namespace Division {
	class DIVISION_API MouseMovedEvent : public Event {
		float _mouseX;
		float _mouseY;
	public:
		inline float GetX() const { return _mouseX; }
		inline float GetY() const { return _mouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class DIVISION_API MouseScrolledEvent : public Event {
		float _xOffset;
		float _yOffset;
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {}
		inline float GetXOffset() const { return _xOffset; }
		inline float GetYOffset() const { return _yOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class DIVISION_API MouseButtonEvent : Event {
		int _button;
	public:
		inline int GetMouseButton() const { return _button; }
	};
}

#endif // !MOUSE_EVENT_H
