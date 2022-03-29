#ifndef GUI_LAYER_H
#define GUI_LAYER_H
#include "Division/Layer/Layer.h"
#include "Division/Events/KeyEvent.h"
#include "Division/Events/AppEvent.h"
#include "Division/Events/MouseEvent.h"	

namespace Division 
{

	class DIVISION_API GuiLayer : public Layer {
		float _time = 0;
	public:
		GuiLayer();
		~GuiLayer();

		void OnAttach() override;
		void OnDettach() override;

		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
	};

}



#endif // !GUI_LAYER_H

