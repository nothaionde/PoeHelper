#pragma once
#include <string>
#include "src/Utils/Constants.h"
#include "src/ImGui/ImGuiLayer.h"

namespace PoeHelper {
	struct WindowProperties
	{
		std::string m_Title;
		uint32_t m_Width;
		uint32_t m_Height;
		bool m_WindowResizable;
		WindowProperties(const std::string title, uint32_t width, uint32_t height, bool windowResizable)
			: m_Title(title), m_Width(width), m_Height(height), m_WindowResizable(windowResizable)
		{
		}
	};

	class Window
	{
	public:
		virtual ~Window() = default;
		virtual void Update() = 0;
		virtual bool WindowShouldClose() = 0;
		virtual bool IsMinimized() = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void* GetWindowPointer() const = 0;
		virtual ImGuiLayer* GetImGuiLayer() const = 0;
		static Window* Create(const WindowProperties& windowProperties =
			WindowProperties(POE_HELPER_APPLICATION_NAME, POE_HELPER_WIDTH, POE_HELPER_HEIGHT, POE_HELPER_WINDOW_RESIZABLE));
	};
}
