#include "ConfigPanel.h"
#include "src/Utils/WidgetUtils.h"

namespace PoeHelper {
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
			ImGui::Text("PixelBob");

			ImGui::End();
		}

	}
}