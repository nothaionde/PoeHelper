#include "Application.h"
#include <cassert>

namespace PoeHelper {
	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string name, uint32_t width, uint32_t height, bool resizable)
	{
		assert(!s_Instance, "Application already exists!");
		s_Instance = this;
		WindowProperties windowProperties{ name, width, height, resizable };

		m_Window = std::unique_ptr<Window>(Window::Create(windowProperties));
	}
	void Application::Run()
	{
		while (!m_Window->WindowShouldClose())
		{
			if (!m_Window->IsMinimized())
			{
				m_Window->Update();
			}
		}
	}
}