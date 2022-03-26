#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H


#include "Event.h"

namespace Division {
	class DIVISION_API MouseMovedEvent : public Event {
		float _mouseX;
		float _mouseY;
	public:
		MouseMovedEvent(float x, float y) : _mouseX(x), _mouseY(y) {}

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

	class DIVISION_API MouseButtonEvent : public Event {
	protected:
		int _button;
		MouseButtonEvent(int button) : _button(button) {}
	public:
		inline int GetMouseButton() const { return _button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class DIVISION_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class DIVISION_API MouseButtonReleasedEvent : public  MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}
	
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

#endif // !MOUSE_EVENT_H
