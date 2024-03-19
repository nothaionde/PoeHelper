#include "GLFWInput.h"
#include "src/Core/Application.h"
#include "vendor/glfw/include/GLFW/glfw3.h"

namespace PoeHelper {
	Input* Input::Create()
	{
		return new GLFWInput();
	}
	GLFWInput::GLFWInput()
	{
	}
	GLFWInput::~GLFWInput()
	{
	}
	bool GLFWInput::IsMouseButtonPressed(MouseCode mouseCode)
	{
		auto* windowPtr = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetWindowPointer());
		int currentState = glfwGetMouseButton(windowPtr, static_cast<uint32_t>(mouseCode));
		static int previousState = GLFW_RELEASE;
		bool isPressed = currentState == GLFW_PRESS && previousState != GLFW_PRESS;
		previousState = currentState;
		return isPressed;
	}
}
