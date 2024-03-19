#pragma once
#include <cstdint>

namespace PoeHelper {
	using MouseCode = int32_t;

	namespace Mouse {
		enum : MouseCode
		{
			// From glfw
			MouseButton1 = 0,
			MouseButton2 = 1,
			MouseButton3 = 2,
			MouseButton4 = 3,
			MouseButton5 = 4,
			MouseButton6 = 5,
			MouseButton7 = 6,
			MouseButton8 = 7,
			MouseButtonLast = 7,
			MouseButtonLeft = 0,
			MouseButtonRight = 1,
			MouseButtonMiddle = 2,
		};
	}
}
