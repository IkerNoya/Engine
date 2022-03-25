#ifndef EVENT_H
#define EVENT_H

#include "../Core.h"
#include <string>
#include <functional>

namespace Division
{
	//Events are currently blocking, when an event occurs it inmediately gets dispatched and must be dealt with in the moment.
	//in the future, try to buffer events in an event bus and process them during the "event" part of the update stage
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, 
		AppTick, AppUpdate, AppRenderer, 
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type; }\
															virtual EventType GetEventType() const override { return GetStaticType(); }\
															virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class DIVISION_API Event {
	protected:
		bool _handled = false;
	private:
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	};

	class DIVISION_API EventDispatcher {
		Event& _event;

		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& newEvent) : _event(newEvent) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (_event.GetEventType() == T::GetStaticType()) {
				_event._handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString(); 
	}
}

#endif // !EVENT_H
