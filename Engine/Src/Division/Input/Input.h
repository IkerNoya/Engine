#ifndef INPUT_H
#define INPUT_H
#include "Division/Core.h"

namespace Division 
{
	class DIVISION_API Input{

		static Input* _instance;

	public :
		inline static bool IsKeyPressed(int keycode) { return _instance->IsKeyPressed_Implementation(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return _instance->IsMouseButtonPressed_Implementation(button); }
		inline static float GetMouseX() { return _instance->GetMouseX_Implementation(); }
		inline static float GetMouseY() { return _instance->GetMouseY_Implementation(); }
		inline static std::pair<float, float> GetMousePosition() { return _instance->GetMousePosition_Implementation(); }

	protected:
		virtual bool IsKeyPressed_Implementation(int keycode) = 0;
		virtual bool IsMouseButtonPressed_Implementation(int button) = 0;
		virtual float GetMouseX_Implementation() = 0;
		virtual float GetMouseY_Implementation() = 0;
		virtual std::pair<float, float> GetMousePosition_Implementation() = 0;

	};
}


#endif // !INPUT_H


