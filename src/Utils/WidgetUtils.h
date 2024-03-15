#pragma once

#include "vendor/imgui-docking/imgui.h"
#include "vendor/imgui-docking/backends/imgui_impl_glfw.h"
#include "vendor/imgui-docking/backends/imgui_impl_opengl3.h"
#include "vendor/imgui-docking/imgui_internal.h"

#include "src/Core/Application.h"

namespace PoeHelper {

	class WidgetUtils
	{
	public:
		static void IconSmall(const char* icon);
	};
}