#include "ImGuiLayer.h"
#include "vendor/glfw/include/GLFW/glfw3.h"
#include "src/Utils/Constants.h"
#include "src/Utils/FileUtils.h"
#include "Panels/CentralDockingSpace.h"

namespace PoeHelper {
	const char* glsl_version = "#version 330";
	ImGuiLayer::ImGuiLayer(GLFWwindow* window)
		: m_Window(window)
	{
		Initialize();
	}
	void ImGuiLayer::Update()
	{
		Begin();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_PopupBorderSize, 1.0f);

		m_HeaderPanel.Draw();
		CentralDockingSpace::Draw();
		m_ConfiguraionPanel.Draw();
		ImGui::ShowDemoWindow();

		ImGui::PopStyleVar();
		ImGui::PopStyleVar();

		End();
	}

	// FIXME: Add cyrillic font support
	void ImGuiLayer::Initialize()
	{
		m_FooterSize = 20.0f;
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		std::string fontAwesome = FileUtils::GetAbsolutePath(POE_HELPER_FONT_AWESOME_FONT_PATH);
		std::string defaultFont = FileUtils::GetAbsolutePath(POE_HELPER_FONT_DEFAULT_FONT_PATH);
		constexpr float baseFontSize = 20.0f; // 13.0f is the size of the default font. Change to the font size you use.
		constexpr float iconFontSize = baseFontSize * 2.0f / 3.0f; // FontAwesome fonts need to have their sizes reduced by 2.0f/3.0f in order to align correctly
		ImFontConfig config;
		config.MergeMode = true;
		io.FontDefault = io.Fonts->AddFontFromFileTTF(defaultFont.c_str(), baseFontSize, NULL, io.Fonts->GetGlyphRangesCyrillic());

		// merge in icons from Font Awesome
		static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
		ImFontConfig icons_config;
		icons_config.MergeMode = true;
		icons_config.PixelSnapH = true;
		icons_config.GlyphMinAdvanceX = iconFontSize;
		m_SmallFont = io.Fonts->AddFontFromFileTTF(fontAwesome.c_str(), iconFontSize, &icons_config, icons_ranges);
		m_DefaultFont = io.FontDefault;
		io.Fonts->Build();

		io.ConfigWindowsMoveFromTitleBarOnly = true;
		io.ConfigDockingTransparentPayload = true;

		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowMenuButtonPosition -= 1; // Get rid of annoying menu button position

		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init();
		m_HeaderPanel.Initialize(ID_HEADER, nullptr);
		m_ConfiguraionPanel.Initialize(ID_CONFIGURATION, ICON_FA_GEAR);
	}
	void ImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}
	void ImGuiLayer::End()
	{
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}
}
