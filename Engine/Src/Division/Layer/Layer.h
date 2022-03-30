#ifndef LAYER_H
#define LAYER_H
#include "Division/Core.h"
#include "Division/Events/Event.h"
namespace Division
{
	class DIVISION_API Layer
	{
	protected:
		std::string _debugName;

	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDettach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}
		virtual void OnGuiRender() {}

		inline const std::string& GetName() const { return _debugName; }
	};
}

#endif // !LAYER_H


