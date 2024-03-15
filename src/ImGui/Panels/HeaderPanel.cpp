#include "HeaderPanel.h"
#include "src/Utils/Constants.h"
#include "src/Core/Application.h"
#include "src/Utils/TextureUtils.h"

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
			Application::GetInstance().GetWindow().GetImGuiLayer()->m_HeaderSize = ImGui::GetWindowSize().y;
			ImGui::Text(POE_HELPER_APPLICATION_NAME.c_str());

			ImGui::SameLine();
			ImGui::Image((void*)logo, POE_HELPER_ICON_DIMENSIONS, ImVec2(0, 0), ImVec2(1, 1));

			ImGui::SameLine();

			// Extract to the method
			ImVec2 windowPos = ImGui::GetWindowPos();
			float  windowWidth = ImGui::GetWindowWidth();

			const float  offset1 = 35.0f;
			const float  gap = 25.0f;
			const ImVec2 buttonSize = ImVec2(25, 20);
			const float  closeButtonAdditionalSize = 8;
			const float  frameRounding = 0.4f;
			ImGui::SetCursorPosY(6);
			const float cursorY = ImGui::GetCursorPosY();
			ImGui::SetCursorPosX(windowWidth - offset1 - closeButtonAdditionalSize - gap * 2);
			// !Extract to the method

			ImGui::PopStyleColor();
			ImGui::End();
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
	}
}
