#pragma once
#include "Panel.h"

namespace PoeHelper {
	class ConfigPanel : public Panel
	{
	public:
		ConfigPanel() = default;
		virtual ~ConfigPanel() = default;
		virtual void Initialize(const char* id, const char* icon) override;
		virtual void Draw() override;
	private:
		ImGuiWindowFlags m_windowFlags;
	};
}