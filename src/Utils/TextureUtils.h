#pragma once

#define GLFW_INCLUDE_NONE
#include "vendor/glad/include/glad/gl.h"
#include "vendor/glfw/include/GLFW/glfw3.h"

namespace PoeHelper {
	class TextureUtils
	{
	public:
		static bool LoadTextureFromFile(const char* filename);
	};
}
