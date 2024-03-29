#pragma once
#include <map>
#include "vendor/imgui-docking/imgui.h"

namespace PoeHelper {
#define POE_HELPER_CRAFTING_COLOR "Colors"

#define POE_HELPER_COLOR_RED IM_COL32(220, 50, 0, 100)
#define POE_HELPER_COLOR_GREEN IM_COL32(90, 210, 55, 100)
#define POE_HELPER_COLOR_BLUE IM_COL32(55, 90, 220, 100)

	class PoeHelperCraftingConstants
	{
	public:
		static void Initialize();
	private:
		friend class ConfigPanel;
		// Config Panel Checkbox settings
		static std::map<const char*, std::map<const char*, bool>> configPanelCheckboxes;
		static const char* sixLinksLabelText;
		static const char* sixLinksLabel;
		static bool sixLinksEnabled;
		static const char* sixSocketsLabelText;
		static const char* sixSocketsLabel;
		static bool sixSocketsEnabled;
		static const char* colorCraftingLabelText;
		static const char* colorCraftingLabel;
		static bool colorCraftingEnabled;
		static const char* orbOfChanceLabelText;
		static const char* orbOfChanceLabel;
		static bool orbOfChanceEnabled;
		static const char* stackedDeckLabelText;
		static const char* stackedDeckLabel;
		static bool stackedDeckEnabled;
		// !Config Panel Checkbox settings

		// Config Panel Socket Colors settings
		static const char* socketCount[7];
		static const char* countOfRedSockets;
		static const char* countOfGreenSockets;
		static const char* countOfBlueSockets;
		// !Config Panel Socket Colors settings
	};
}
