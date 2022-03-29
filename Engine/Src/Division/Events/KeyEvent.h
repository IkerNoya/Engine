#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include "Event.h"

namespace Division {
	class DIVISION_API KeyEvent : public Event {
	protected:
		int _keyCode;
		KeyEvent(int keycode) : _keyCode(keycode) {}

	public:
		inline int GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	class DIVISION_API KeyPressedEvent : public KeyEvent {
		int _repeatCount;
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {	}
		inline int GetRepeatCount() const { return _repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keyCode << " (" << _repeatCount <<" repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class DIVISION_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode){}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class DIVISION_API KeyTypedEvent : public KeyEvent {
		int _keyCode;
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode) {	}
		
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

}

#endif // !KEY_EVENT_H

