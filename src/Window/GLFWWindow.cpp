#include "GLFWWindow.h"
#include "src/Utils/TextureUtils.h"
#include <cassert>

namespace PoeHelper {
	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int error, const char* description)
	{
	}
	Window* Window::Create(const WindowProperties& windowProperties)
	{
		return new GLFWWindow(windowProperties);
	}

	GLFWWindow::GLFWWindow(const WindowProperties windowProperties)
	{
		Initialize(windowProperties);
	}
	GLFWWindow::~GLFWWindow()
	{
		glfwDestroyWindow(m_Window);
	}
	void GLFWWindow::Update()
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		m_ImGuiLayer->Update();
		glfwSwapBuffers(m_Window);
		if (m_WindowShouldSetNewPos)
		{
			m_WindowShouldSetNewPos = false;
			glfwSetWindowPos(m_Window, m_WindowData.m_XPos, m_WindowData.m_YPos);
		}
	}
	bool GLFWWindow::WindowShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}
	bool GLFWWindow::IsMinimized()
	{
		return false;
	}
	void GLFWWindow::SetWindowPosition(uint32_t xPos, uint32_t yPos)
	{
		m_WindowData.m_XPos = xPos;
		m_WindowData.m_YPos = yPos;
		m_WindowShouldSetNewPos = true;
	}
	void GLFWWindow::SetWindowShouldClose(bool shouldClose)
	{
		glfwSetWindowShouldClose(m_Window, shouldClose ? GLFW_TRUE : GLFW_FALSE);
	}
	// TODO: Window should be always on top only when auto craft is enabled
	void GLFWWindow::SetWindowAlwaysOnTop(bool onTop)
	{
		glfwSetWindowAttrib(m_Window, GLFW_FLOATING, onTop ? GLFW_TRUE : GLFW_FALSE);
	}
	void GLFWWindow::Initialize(const WindowProperties windowProperties)
	{
		m_WindowShouldSetNewPos = false;
		m_WindowData.m_Title = windowProperties.m_Title;
		m_WindowData.m_Width = windowProperties.m_Width;
		m_WindowData.m_Height = windowProperties.m_Height;
		if (!s_GLFWInitialized)
		{
			int error = glfwInit();
			assert(error == GLFW_TRUE);
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}
		glfwWindowHint(GLFW_RESIZABLE, windowProperties.m_WindowResizable ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		m_Window = glfwCreateWindow(windowProperties.m_Width, windowProperties.m_Height, windowProperties.m_Title.c_str(), NULL, NULL);
		// TODO: remove next line after serialization and deserialization
		SetWindowPosition(100, 100);
		glfwMakeContextCurrent(m_Window);
		gladLoadGL(glfwGetProcAddress);
		glfwSwapInterval(GLFW_TRUE);

		GLFWimage icon[1];
		icon[0].pixels = TextureUtils::GetPixelsFromFile(POE_HELPER_ICON_LOGO);
		glfwSetWindowIcon(m_Window, 1, icon);

		m_ImGuiLayer = std::make_unique<ImGuiLayer>(m_Window);
	}
}
