#include "ConfigPanel.h"
#include "src/Utils/WidgetUtils.h"
#include "src/ApplicationLogic/PoeHelperCraftingConstants.h"

namespace PoeHelper {

	bool ConfigPanel::m_ShowHotkeys = false;
	bool ConfigPanel::m_ShowSettings = false;

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

			static auto contentRegionAvailable = ImGui::GetContentRegionAvail();
			static auto nextTwoButtonsWidth = contentRegionAvailable.x / 2 - contentRegionAvailable.x * 0.1f;
			if (ImGui::Button("Hotkeys", ImVec2(nextTwoButtonsWidth, 0.0f)))
			{
				m_ShowHotkeys = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("Settings", ImVec2(nextTwoButtonsWidth, 0.0f)))
			{
				m_ShowSettings = true;
			}
			if (m_ShowHotkeys)
			{
				ShowHotkeysWindow();
			}
			if (m_ShowSettings)
			{
				ShowSettingsWindow();
			}
			ImGui::End();
		}
	}
	void ConfigPanel::ShowHotkeysWindow()
	{
		static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDocking;
		flags |= ImGuiWindowFlags_NoResize;
		static ImVec2 hotkeysWindowDimensions = ImVec2(400, 600);
		ImGui::SetNextWindowSize(hotkeysWindowDimensions);
		if (ImGui::Begin("Hotkeys", NULL, flags))
		{
			if (ImGui::Button("Close##Hotkeys", ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				m_ShowHotkeys = false;
			}
			ImGui::End();
		}
	}
	void ConfigPanel::ShowSettingsWindow()
	{
		static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDocking;
		flags |= ImGuiWindowFlags_NoResize;
		static ImVec2 hotkeysWindowDimensions = ImVec2(400, 600);
		ImGui::SetNextWindowSize(hotkeysWindowDimensions);
		if (ImGui::Begin("Settings", NULL, flags))
		{
			if (ImGui::Button("Close##Settings", ImVec2(ImGui::GetContentRegionAvail().x, 0)))
			{
				m_ShowSettings = false;
			}
			ImGui::ShowDemoWindow();
			static bool humanBehaviorSimulation;
			static int craftDelay = 50;
			static int unloadingDelay = 50;
			static int stepForSettingDelay = 50;
			static const char* buttonToHoldToSpam[] = {"Shift", "Space"};
			static const char* buttonToHoldToSpamSelected = "Shift";
			ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.5f);
			if (ImGui::BeginCombo("Hold Button To Spam##asd", buttonToHoldToSpamSelected))
			{
				for (int i = 0; i < IM_ARRAYSIZE(buttonToHoldToSpam); i++)
				{
					bool selected = (buttonToHoldToSpamSelected == buttonToHoldToSpam[i]);
					if (ImGui::Selectable(buttonToHoldToSpam[i], selected))
					{
						buttonToHoldToSpamSelected = buttonToHoldToSpam[i];
					}
					if (selected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
			ImGui::Checkbox("Human Behavior Simulation", &humanBehaviorSimulation);
			ImGui::InputInt("Craft delay, ms", &craftDelay, stepForSettingDelay);
			ImGui::InputInt("Unloading delay, ms", &unloadingDelay, stepForSettingDelay);
			ImGui::PopItemWidth();
			if (ImGui::BeginTable("Table Of Crafting Currency Positions", 3))
			{
				ImGui::TableSetupColumn("Currency");
				ImGui::TableSetupColumn("X");
				ImGui::TableSetupColumn("Y");

				ImGui::TableHeadersRow();

				ImGui::EndTable();
			}
			if (craftDelay < 0)
			{
				craftDelay = 0;
			}
			if (unloadingDelay < 0)
			{
				unloadingDelay = 0;
			}
			ImGui::End();
		}
	}
}
