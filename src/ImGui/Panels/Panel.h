#pragma once

#include "vendor/IconFontCppHeaders/IconsFontAwesome6.h"
#include "vendor/imgui-docking/imgui.h"
#include "vendor/imgui-docking/imgui_internal.h"
#include "vendor/imgui-docking/backends/imgui_impl_glfw.h"
#include "vendor/imgui-docking/backends/imgui_impl_opengl3.h"
#include <string>

namespace PoeHelper {
	class Panel
	{
	public:
		Panel() = default;
		virtual ~Panel() = default;
		virtual void Draw() = 0;
		virtual void Initialize(const char* id, const char* icon);
	protected:
		const char* m_Id = nullptr;
		const char* m_Icon = nullptr;
		std::string m_Title = "";
	};
}
