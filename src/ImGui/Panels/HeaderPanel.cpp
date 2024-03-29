#include "HeaderPanel.h"
#include "src/Utils/Constants.h"
#include "src/Core/Application.h"
#include "src/Utils/TextureUtils.h"
#include "src/Utils/WidgetUtils.h"
#include "src/Core/Input.h"

#include "vendor/glad/include/glad/gl.h"

namespace PoeHelper {
	GLuint logo;
	void HeaderPanel::Initialize(const char* id, const char* icon)
	{
		Panel::Initialize(id, icon);
		// Initializing logo image, TODO: may be move initialization to a separate function
		logo = TextureUtils::LoadTextureFromFile(POE_HELPER_ICON_LOGO);
		IM_ASSERT(logo != 0);
	}
	void HeaderPanel::Draw()
	{
		ImGuiWindowFlags headerFlags = ImGuiWindowFlags_NoDocking;
		headerFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
		headerFlags |= ImGuiWindowFlags_NoTitleBar;
		headerFlags |= ImGuiWindowFlags_NoResize;
		headerFlags |= ImGuiWindowFlags_NoScrollbar;
		headerFlags |= ImGuiWindowFlags_NoDecoration;
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(ImVec2(viewport->WorkPos.x, viewport->WorkPos.y));
		ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, POE_HELPER_HEADER_HEIGHT));

		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImGui::GetStyleColorVec4(ImGuiCol_MenuBarBg));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 8.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f);

		if (ImGui::Begin(m_Id, NULL, headerFlags))
		{
			HandleWindowMovement();
			Application::GetInstance().GetWindow().GetImGuiLayer()->m_HeaderSize = ImGui::GetWindowSize().y;

			ImGui::SetCursorPosX(POE_HELPER_DEFAULT_TAB_SIZE);
			ImGui::Text(POE_HELPER_APPLICATION_NAME.c_str());

			ImGui::SameLine();

			// Add a poly background and the logo.
			const ImVec2 windowPos = ImVec2((float)Application::GetInstance().GetWindow().GetPosX(), (float)Application::GetInstance().GetWindow().GetPosY());
			const ImVec2 windowSize = ImVec2((float)Application::GetInstance().GetWindow().GetWidth(), (float)Application::GetInstance().GetWindow().GetHeight());
			const ImVec2 logoBounds = ImVec2(POE_HELPER_ICON_DIMENSIONS.x * 3, POE_HELPER_ICON_DIMENSIONS.y);
			const ImVec2 logoPos = ImVec2(windowPos.x + windowSize.x / 2.0f - logoBounds.x / 2.0f, windowPos.y);
			const ImVec2 points[5] = {
					ImVec2(logoPos.x, logoPos.y),
					ImVec2(logoPos.x + 20, logoPos.y + Application::GetInstance().GetWindow().GetImGuiLayer()->m_HeaderSize / 2.0f + 4),
					ImVec2(logoPos.x + logoBounds.x - 20, logoPos.y + Application::GetInstance().GetWindow().GetImGuiLayer()->m_HeaderSize / 2.0f + 4),
					ImVec2(logoPos.x + logoBounds.x, logoPos.y),
					ImVec2(logoPos.x, logoPos.y) };
			const ImU32 polyBackground = ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Border));
			ImGui::GetWindowDrawList()->AddConvexPolyFilled(&points[0], 5, polyBackground);
			ImGui::GetWindowDrawList()->AddPolyline(&points[0], 4, ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 0.0f, 0.0f, 0.5f)), 0, 3);
			const ImVec2 logoMin = ImVec2(windowPos.x + viewport->WorkSize.x / 2.0f - POE_HELPER_ICON_DIMENSIONS.x / 2.0f, windowPos.y + logoBounds.y / 2.0f - POE_HELPER_ICON_DIMENSIONS.y / 2.0f);
			const ImVec2 logoMax = ImVec2(logoMin.x + POE_HELPER_ICON_DIMENSIONS.x, logoMin.y + POE_HELPER_ICON_DIMENSIONS.y);
			ImGui::GetWindowDrawList()->AddImage((void*)logo, logoMin, logoMax, ImVec2(1, 0), ImVec2(0, 1));

			ImGui::SameLine();
			WidgetUtils::WindowButtons(4.0f);

			ImGui::PopStyleColor();
			ImGui::End();
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
	}
	void HeaderPanel::HandleWindowMovement()
	{
		if (ImGui::IsWindowHovered())
		{
			static bool isDragging = false;
			static ImVec2 mouseDelta = ImVec2(0, 0);
			static ImVec2 mousePosition = ImVec2();
			if (Application::GetInstance().GetInput().IsMouseButtonPressed(Mouse::MouseButton1))
			{
				mousePosition = ImVec2(Application::GetInstance().GetWindow().GetPosX(), Application::GetInstance().GetWindow().GetPosY());
			}
			isDragging = ImGui::IsMouseDragging(ImGuiMouseButton_Left);
			if (isDragging)
			{
				ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeAll);
				mouseDelta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Left);
				Application::GetInstance().GetWindow().SetWindowPosition(mousePosition.x + (int)mouseDelta.x, mousePosition.y + (int)mouseDelta.y);
			}
		}
	}
}
