#pragma once
#include <string>
#include "vendor/IconFontCppHeaders/IconsFontAwesome6.h"
#include "vendor/imgui-docking/imgui.h"
#include "vendor/imgui-docking/backends/imgui_impl_glfw.h"
#include "vendor/imgui-docking/backends/imgui_impl_opengl3.h"

// Application main settings
#define POE_HELPER_VERSION "0.01"
#define POE_HELPER_WIDTH 400
#define POE_HELPER_HEIGHT 800
#define POE_HELPER_APPLICATION_NAME std::string("Poe Helper v." + std::string(POE_HELPER_VERSION))
#define POE_HELPER_WINDOW_RESIZABLE false
#define POE_HELPER_FONT_AWESOME_FONT_PATH std::string("res\\fonts\\" + std::string(FONT_ICON_FILE_NAME_FAS))
#define POE_HELPER_FONT_DEFAULT_FONT_PATH std::string("res\\fonts\\" + std::string("Fontin-Regular.ttf"))
// !Application main settings

// Application footer and header sizes
#define POE_HELPER_FOOTER_HIEGHT 20
#define POE_HELPER_HEADER_HEIGHT 60.0f
#define POE_HELPER_FOOTER_SIZE 20.0f
#define POE_HELPER_HEADER_SIZE 0.0f
// ! footer and header sizes

// Application logo settings
#define POE_HELPER_ICON_LOGO "res\\textures\\logo.png"
#define POE_HELPER_ICON_DIMENSIONS ImVec2(28, 28)
#define POE_HELPER_ICON_MINUS ICON_FA_MINUS
#define POE_HELPER_ICON_TIMES ICON_FA_XMARK
// !Application logo settings

// Application dockspace id
#define POE_HELPER_DOCKSPACE_ID "Poe Helper Dockspace"
#define POE_HELPER_DOCKSPACE_BEGIN_ID "Poe Helper Dock Space"

#define POE_HELPER_ID_DOCK_MAIN "id_dock_main"
// !Application dockspace id

// Application Font Awesome icons
#define POE_HELPER_ICON_CONFIG_WINDOW ICON_FA_GEAR
// !Application Font Awesome icons

namespace PoeHelper {
	struct WindowConstants
	{
		uint32_t m_XPos;
		uint32_t m_YPos;
	};

	class Constants
	{
	public:
		Constants();
		~Constants() = default;
		void InitializeDefaultValues();
	private:
		WindowConstants m_WindowConstants;
	};
}
