#pragma once
#include "MouseCodes.h"

namespace PoeHelper {
	class Input
	{
	public:
		virtual ~Input() = default;
		virtual bool IsMouseButtonPressed(MouseCode mouseCode) = 0;
		static Input* Create();
	};
}
