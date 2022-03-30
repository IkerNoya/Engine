#include "dpch.h"
#include "GuiLayer.h"
#include <imgui.h>
#include <glad/glad.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include "Division/Application/Application.h"
#include "Division/Input/KeyCodes.h"
#include "Division/Input/MouseButtonCodes.h"


namespace Division 
{
	GuiLayer::GuiLayer() : Layer("GuiLayer") {

	}
	GuiLayer::~GuiLayer() {

	}

	void GuiLayer::OnAttach(){
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Delete] = KEYCODE_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = KEYCODE_BACKSPACE;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void GuiLayer::OnDettach(){

	}

	void GuiLayer::OnUpdate() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		float time = (float)glfwGetTime();
		io.DeltaTime = _time > 0.f ? (time - _time) : (1.f / 60.f);
		_time = time;

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GuiLayer::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseButtonPressedEvent>(DIV_BIND_EVENT(GuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(DIV_BIND_EVENT(GuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(DIV_BIND_EVENT(GuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<MouseMovedEvent>(DIV_BIND_EVENT(GuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<KeyPressedEvent>(DIV_BIND_EVENT(GuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(DIV_BIND_EVENT(GuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(DIV_BIND_EVENT(GuiLayer::OnKeyTypedEvent));
	}

	bool GuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;
		//queda en falso para que otras layers lo puedan usar, asi no consume el evento de mouse
		return false;
	}

	bool GuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;
		return false;
	}

	bool GuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		return false;
	}

	bool GuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();
		return false;
	}

	bool GuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[KEYCODE_LCONTROL] || io.KeysDown[KEYCODE_RCONTROL];
		io.KeyShift = io.KeysDown[KEYCODE_LSHIFT] || io.KeysDown[KEYCODE_RSHIFT];
		io.KeyAlt = io.KeysDown[KEYCODE_LALT] || io.KeysDown[KEYCODE_RALT];
		io.KeySuper = io.KeysDown[KEYCODE_LSUPER] || io.KeysDown[KEYCODE_RSUPER];

		return false;
	}

	bool GuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool GuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();

		if (keycode > 0 && keycode < 0x10000) {
			io.AddInputCharacter((unsigned short)keycode);
		}

		return false;
	}

	bool GuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0, 1.0);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}
}