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
		static void WindowButtons(float yOffset, float sizeMultiplier = 1.0f, const char* windowID = nullptr, bool isAppWindow = true);
		static bool CreateIconButton(const char* icon, const ImVec2& size = ImVec2(0, 0), float rounding = 0.0f, const ImVec2& spacing = ImVec2(0.0f, 0.0f), bool isAppWindow = false, const char* windowID = nullptr);
	};
}