#include "PoeHelperCraftingConstants.h"

namespace PoeHelper {
	// Config Panel Checkbox settings
	const char* PoeHelperCraftingConstants::sixLinksLabelText = "Six Links";
	const char* PoeHelperCraftingConstants::sixLinksLabel = "##sixLinksLabel";
	bool PoeHelperCraftingConstants::sixLinksEnabled = false;
	const char* PoeHelperCraftingConstants::sixSocketsLabelText = "Six Sockets";
	const char* PoeHelperCraftingConstants::sixSocketsLabel = "##sixSocketsLabel";
	bool PoeHelperCraftingConstants::sixSocketsEnabled = false;
	const char* PoeHelperCraftingConstants::colorCraftingLabelText = POE_HELPER_CRAFTING_COLOR;
	const char* PoeHelperCraftingConstants::colorCraftingLabel = "##colorCraftingLabel";
	bool PoeHelperCraftingConstants::colorCraftingEnabled = false;
	const char* PoeHelperCraftingConstants::orbOfChanceLabelText = "Chance";
	const char* PoeHelperCraftingConstants::orbOfChanceLabel = "##orbOfChanceLabel";
	bool PoeHelperCraftingConstants::orbOfChanceEnabled = false;
	const char* PoeHelperCraftingConstants::stackedDeckLabelText = "Stacked Decks";
	const char* PoeHelperCraftingConstants::stackedDeckLabel = "##stackedDeckLabel";
	bool PoeHelperCraftingConstants::stackedDeckEnabled = false;
	std::map<const char*, std::map<const char*, bool>> PoeHelperCraftingConstants::configPanelCheckboxes;
	// !Config Panel Checkbox settings

	// Config Panel Socket Colors settings
	const char* PoeHelperCraftingConstants::socketCount[] = { "0", "1", "2", "3", "4", "5", "6" };
	const char* PoeHelperCraftingConstants::countOfRedSockets = PoeHelperCraftingConstants::socketCount[0];
	const char* PoeHelperCraftingConstants::countOfGreenSockets = PoeHelperCraftingConstants::socketCount[0];
	const char* PoeHelperCraftingConstants::countOfBlueSockets = PoeHelperCraftingConstants::socketCount[0];
	// !Config Panel Socket Colors settings

	void PoeHelperCraftingConstants::Initialize()
	{
		configPanelCheckboxes.insert({
		sixLinksLabelText, {{sixLinksLabel, sixLinksEnabled}}
			});

		configPanelCheckboxes.insert({
			sixSocketsLabelText, {{sixSocketsLabel, sixSocketsEnabled}}
			});

		configPanelCheckboxes.insert({
			colorCraftingLabelText, {{colorCraftingLabel, colorCraftingEnabled}}
			});

		configPanelCheckboxes.insert({
			orbOfChanceLabelText, {{orbOfChanceLabel, orbOfChanceEnabled}}
			});

		configPanelCheckboxes.insert({
			stackedDeckLabelText, {{stackedDeckLabel, stackedDeckEnabled}}
			});
	}
}
