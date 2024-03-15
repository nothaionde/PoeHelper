#pragma once

#include <memory>

#include "src/Core/Window.h"

#define GLFW_INCLUDE_NONE
#include "vendor/glad/include/glad/gl.h"
#include "vendor/glfw/include/GLFW/glfw3.h"

namespace PoeHelper {
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowProperties windowProperties);
		virtual ~GLFWWindow();

		void Update() override;

		bool WindowShouldClose() override;
		bool IsMinimized() override;
		inline uint32_t GetWidth() const override
		{
			return m_WindowData.m_Width;
		};
		inline uint32_t GetHeight() const override
		{
			return m_WindowData.m_Height;
		}
		inline void* GetWindowPointer() const override
		{
			return m_Window;
		}
		inline ImGuiLayer* GetImGuiLayer() const override
		{
			return m_ImGuiLayer.get();
		}
	private:
		virtual void Initialize(const WindowProperties windowProperties);

	private:
		GLFWwindow* m_Window;
		std::unique_ptr<ImGuiLayer> m_ImGuiLayer;
		struct WindowData
		{
			std::string m_Title;
			uint32_t m_Width;
			uint32_t m_Height;
		};
		WindowData m_WindowData;
	};
}
