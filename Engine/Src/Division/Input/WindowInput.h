#ifndef WINDOWS_INPUT_H
#define WINDOWS_INPUT_H

#include "Input.h"

namespace Division
{
	class WindowInput : public Input {
	protected:
		virtual bool IsKeyPressed_Implementation(int keycode) override;

		virtual bool IsMouseButtonPressed_Implementation(int button) override;
		virtual float GetMouseX_Implementation() override;
		virtual float GetMouseY_Implementation() override;
		virtual std::pair<float, float> GetMousePosition_Implementation() override;
	};

}


#endif // !WINDOWS_INPUT_H

