#ifndef APP_H
#define APP_H
#include "Division/Core.h"
#include "Division/Events/Event.h"
#include "Division/Events/AppEvent.h"
#include "Division/Layer/LayerStack.h"

#include "Division/GUI/GuiLayer.h"

#include "Division/Window/WindowInterface.h"

namespace Division
{
	//solo hay uno por motor/app
	class DIVISION_API Application
	{
		static Application* _instance;
		//unique indica que solo esta clase posee este puntero/instancia
		std::unique_ptr<WindowInterface> _window;
		std::unique_ptr<class Shader> _shader;
		std::unique_ptr<class VertexBuffer> _vertexBuffer;
		std::unique_ptr<class IndexBuffer> _indexBuffer;

		GuiLayer* _guiLayer;
		LayerStack _layerStack;
		bool _running = true;
		unsigned int _vao;
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline WindowInterface& GetWindow() { return *_window; }
		inline static Application& Get() { return *_instance; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
	};
	Application* CreateApplication();
}


#endif // !APP_H



