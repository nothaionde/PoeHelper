#pragma once
#include <string>
#include <memory>
#include <vector>

#include "src/Core/Window.h"
#include "src/ImGui/ImGuiLayer.h"

namespace PoeHelper {
	class Application
	{
	public:
		Application(const std::string name, uint32_t width, uint32_t height, bool resizable);
		virtual ~Application() = default;

		void Run();
		Window& GetWindow()
		{
			return *m_Window;
		}
		static Application& GetInstance()
		{
			return *s_Instance;
		}
	private:
		static Application* s_Instance;
		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
	};
}
