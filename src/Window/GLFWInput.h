#pragma once

#include "src/Core/Input.h"

namespace PoeHelper {
	class GLFWInput : public Input
	{
	public:
		GLFWInput();
		virtual ~GLFWInput();
		bool IsMouseButtonPressed(MouseCode mouseCode) override;
	};
}
