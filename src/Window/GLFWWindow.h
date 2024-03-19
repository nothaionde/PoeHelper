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

		inline uint32_t GetPosX() const override
		{
			return m_WindowData.m_XPos;
		}
		inline uint32_t GetPosY() const override
		{
			return m_WindowData.m_YPos;
		}
		void SetWindowPosition(uint32_t xPos, uint32_t yPos) override;
		inline void* GetWindowPointer() const override
		{
			return m_Window;
		}
		inline ImGuiLayer* GetImGuiLayer() const override
		{
			return m_ImGuiLayer.get();
		}
		void SetWindowShouldClose(bool shouldClose) override;
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
			uint32_t m_XPos;
			uint32_t m_YPos;
		};
		WindowData m_WindowData;
	};
}
