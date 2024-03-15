#include "WidgetUtils.h"

namespace PoeHelper {
	void WidgetUtils::IconSmall(const char* icon)
	{
		ImGui::PushFont(Application::GetInstance().GetWindow().GetImGuiLayer()->GetSmallFont());
		ImGui::Text(icon);
		ImGui::PopFont();
	}
}