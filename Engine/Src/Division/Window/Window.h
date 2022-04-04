#ifndef WINDOW_H
#define WINDOW_H

#include "WindowInterface.h"
#include "Division/Renderer/RendererContext.h"
#include <GLFW/glfw3.h>

namespace Division
{
	//no tiene que conocer a application
	class DIVISION_API Window : public WindowInterface {
		GLFWwindow* _window;
		struct WindowData {
			std::string title;
			unsigned int width;
			unsigned int height;
			bool vsync;

			EventCallbackFn EventCallback;
		};
		WindowData _data;
		RendererContext* _context;

	public:
		Window(const WindowProperties& properties);
		virtual ~Window();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return _data.width; }
		inline unsigned int GetHeight() const override { return _data.height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSyncEnabled() const override;

		inline void* GetNativeWindow() const override {
			return _window;
		}

	private:
		virtual void Init(const WindowProperties& properties);
		virtual void ShutDown();
		void SetCallbacks();

		 
	};
}


#endif // !WINDOW_H



