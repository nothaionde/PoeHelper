#include "WidgetUtils.h"
#include <src/Utils/Constants.h>

namespace PoeHelper {
	void WidgetUtils::IconSmall(const char* icon)
	{
		ImGui::PushFont(Application::GetInstance().GetWindow().GetImGuiLayer()->GetSmallFont());
		ImGui::Text(icon);
		ImGui::PopFont();
	}
	void WidgetUtils::WindowButtons(float yOffset, float sizeMultiplier, const char* windowID, bool isAppWindow)
	{
		const ImVec2 windowPos = ImGui::GetWindowPos();
		const float windowWidth = ImGui::GetWindowWidth();
		const float offsetFromRight = 20.0f;
		const ImVec2 buttonSize = ImVec2(25 * sizeMultiplier, 20 * sizeMultiplier);
		const float closeButtonAdditionalSize = 8.0f;
		const float frameRounding = 0.4f;

		ImGui::SetCursorPosY(yOffset);
		const float cursorY = ImGui::GetCursorPosY();
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.3f, 0.3f, 1.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.5f, 0.3f, 0.3f, 1.0f));
		ImGui::SetCursorPosX(windowWidth - offsetFromRight - closeButtonAdditionalSize);

		if (CreateIconButton(POE_HELPER_ICON_TIMES, buttonSize, frameRounding, ImVec2(0.0f, -0.6f)))
		{
			Application::GetInstance().GetWindow().SetWindowShouldClose(true);
		}

		ImGui::PopStyleColor(2);
		ImGui::SetCursorPosX(windowWidth - offsetFromRight - closeButtonAdditionalSize - buttonSize.x - closeButtonAdditionalSize);

		ImGui::SetCursorPosY(cursorY);

		if (CreateIconButton(POE_HELPER_ICON_MINUS, buttonSize, frameRounding, ImVec2(0.0f, -0.6f), isAppWindow, windowID))
		{
			if (isAppWindow)
			{
				// Iconify
			}
		}
	}
	bool WidgetUtils::CreateIconButton(const char* icon, const ImVec2& size, float rounding, const ImVec2& spacing, bool isAppWindow, const char* windowID)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, rounding);

		bool buttonPressed = false;
		if (spacing.x == 0.0f && spacing.y == 0.0f)
		{
			buttonPressed = ImGui::Button(icon, size);
		}
		else
		{
			const ImVec2 cursorScreenPos = ImGui::GetCursorScreenPos();
			const std::string buttonId = "##_" + std::string(icon);
			buttonPressed = ImGui::Button(buttonId.c_str(), size);
			std::string labelText = std::string(icon);
			std::string displayText = labelText.substr(0, labelText.find("#"));
			const ImVec2 textSize = ImGui::CalcTextSize(displayText.c_str());
			const ImVec2 textPos = ImVec2(
				cursorScreenPos.x + size.x / 2.0f - textSize.x / 2.0f + spacing.x,
				cursorScreenPos.y + size.y / 2.0f - textSize.y / 2.0f + spacing.y
			);
			ImGui::GetWindowDrawList()->AddText(
				textPos,
				ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)),
				displayText.c_str()
			);
		}

		ImGui::PopStyleVar();

		return buttonPressed;
	}
}
