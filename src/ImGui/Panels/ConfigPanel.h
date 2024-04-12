#pragma once
#include "Panel.h"

namespace PoeHelper {
	class ConfigPanel : public Panel
	{
	public:
		ConfigPanel() = default;
		virtual ~ConfigPanel() = default;
		void UncheckOtherBools(const char* label);
		void DrawColorChoose(const char* item);
		virtual void Initialize(const char* id, const char* icon) override;
		virtual void Draw() override;
	private:
		void ShowHotkeysWindow();
		void ShowSettingsWindow();
	private:
		ImGuiWindowFlags m_windowFlags;
		static bool m_ShowHotkeys;
		static bool m_ShowSettings;
	};
}
