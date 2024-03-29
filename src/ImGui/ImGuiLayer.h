#pragma once

#include "src/Utils/Constants.h"
#include "Panels/ConfigPanel.h"
#include "Panels/HeaderPanel.h"
#include "vendor/imgui-docking/backends/imgui_impl_glfw.h"
#include "vendor/imgui-docking/backends/imgui_impl_opengl3.h"
#include "vendor/imgui-docking/imgui.h"

#define ID_HEADER "Header"
#define ID_CONFIGURATION "Main"
#define ID_FOOTER "Footer"

namespace PoeHelper {
	class ImGuiLayer
	{
	public:
		ImGuiLayer(GLFWwindow* window);
		~ImGuiLayer() = default;
		void Update();
	private:
		void Initialize();
		void Begin();
		void End();
	public:
		float m_HeaderSize = 0.0f;
		float m_FooterSize = 20.0f;
		ImFont* GetSmallFont()
		{
			return m_SmallFont;
		}
	private:
		GLFWwindow* m_Window;
		HeaderPanel m_HeaderPanel;
		ConfigPanel m_ConfiguraionPanel;
		ImFont* m_SmallFont;
		ImFont* m_DefaultFont;
	};
}
