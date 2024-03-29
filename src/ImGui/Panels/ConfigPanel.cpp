#include "ConfigPanel.h"
#include "src/Utils/WidgetUtils.h"
#include "src/ApplicationLogic/PoeHelperCraftingConstants.h"

namespace PoeHelper {
	void ConfigPanel::UncheckOtherBools(const char* label)
	{
		for (auto& tabEntry : PoeHelperCraftingConstants::configPanelCheckboxes)
		{
			if (std::strcmp(tabEntry.first, label) != 0)
			{
				for (auto& checkboxPair : tabEntry.second)
				{
					checkboxPair.second = false;
				}
			}
		}
	}

	void ConfigPanel::DrawColorChoose(const char* item)
	{
		// Color crafting
		if (strcmp(item, POE_HELPER_CRAFTING_COLOR) == 0)
		{
			ImGui::Separator();

			// Red Color
			ImGui::PushStyleColor(ImGuiCol_Button, POE_HELPER_COLOR_RED);
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, POE_HELPER_COLOR_RED);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, POE_HELPER_COLOR_RED);
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, POE_HELPER_COLOR_RED);
			ImGui::PushItemWidth(50);
			if (ImGui::BeginCombo("##Combo red color sockets", PoeHelperCraftingConstants::countOfRedSockets))
			{
				for (int n = 0; n < IM_ARRAYSIZE(PoeHelperCraftingConstants::socketCount); n++)
				{
					bool isSelected = (PoeHelperCraftingConstants::countOfRedSockets == PoeHelperCraftingConstants::socketCount[n]);
					if (ImGui::Selectable(PoeHelperCraftingConstants::socketCount[n], isSelected))
					{
						PoeHelperCraftingConstants::countOfRedSockets = PoeHelperCraftingConstants::socketCount[n];
					}
					if (isSelected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
			ImGui::PopStyleColor(4);
			ImGui::SameLine();

			// Green Color
			ImGui::PushStyleColor(ImGuiCol_Button, POE_HELPER_COLOR_GREEN);
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, POE_HELPER_COLOR_GREEN);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, POE_HELPER_COLOR_GREEN);
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, POE_HELPER_COLOR_GREEN);
			ImGui::PushItemWidth(50);
			if (ImGui::BeginCombo("##Combo green color sockets", PoeHelperCraftingConstants::countOfGreenSockets))
			{
				for (int n = 0; n < IM_ARRAYSIZE(PoeHelperCraftingConstants::socketCount); n++)
				{
					bool isSelected = (PoeHelperCraftingConstants::countOfGreenSockets == PoeHelperCraftingConstants::socketCount[n]);
					if (ImGui::Selectable(PoeHelperCraftingConstants::socketCount[n], isSelected))
					{
						PoeHelperCraftingConstants::countOfGreenSockets = PoeHelperCraftingConstants::socketCount[n];
					}
					if (isSelected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
			ImGui::PopStyleColor(4);
			ImGui::SameLine();

			// Blue Color
			ImGui::PushStyleColor(ImGuiCol_Button, POE_HELPER_COLOR_BLUE);
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, POE_HELPER_COLOR_BLUE);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, POE_HELPER_COLOR_BLUE);
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, POE_HELPER_COLOR_BLUE);
			ImGui::PushItemWidth(50);
			if (ImGui::BeginCombo("##Combo blue color sockets", PoeHelperCraftingConstants::countOfBlueSockets))
			{
				for (int n = 0; n < IM_ARRAYSIZE(PoeHelperCraftingConstants::socketCount); n++)
				{
					bool isSelected = (PoeHelperCraftingConstants::countOfBlueSockets == PoeHelperCraftingConstants::socketCount[n]);
					if (ImGui::Selectable(PoeHelperCraftingConstants::socketCount[n], isSelected))
					{
						PoeHelperCraftingConstants::countOfBlueSockets = PoeHelperCraftingConstants::socketCount[n];
					}
					if (isSelected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
			ImGui::PopStyleColor(4);
			ImGui::Separator();
		}
	}
	void ConfigPanel::Initialize(const char* id, const char* icon)
	{
		Panel::Initialize(id, icon);
		m_windowFlags = ImGuiWindowFlags_NoCollapse;
		m_windowFlags |= ImGuiWindowFlags_NoMove;
		m_windowFlags |= ImGuiWindowFlags_NoTitleBar;
		m_windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
		m_windowFlags |= ImGuiWindowFlags_NoResize;
	}
	void ConfigPanel::Draw()
	{
		ImGuiWindowFlags flags = m_windowFlags;

		ImGui::ShowDemoWindow();

		if (ImGui::Begin(m_Id, NULL, flags))
		{
			for (auto& checkboxMap : PoeHelperCraftingConstants::configPanelCheckboxes)
			{
				ImGui::Text(checkboxMap.first);
				ImGui::SameLine();
				ImGui::SetCursorPosX(300);
				for (auto& currentSelection : checkboxMap.second)
				{
					if (ImGui::Checkbox(currentSelection.first, &currentSelection.second))
					{
						UncheckOtherBools(checkboxMap.first);
					}
					if (currentSelection.second)
					{
						DrawColorChoose(checkboxMap.first);
					}
				}
			}
			ImGui::End();
		}
	}
}
