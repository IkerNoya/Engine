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

		virtual void OnAttach() override;
		virtual void OnDettach() override;

		virtual void OnGuiRender() override;

		void Begin();
		void End();
	};

}



#endif // !GUI_LAYER_H

