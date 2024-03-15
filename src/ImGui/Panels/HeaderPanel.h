#pragma once

#include "Panel.h"

namespace PoeHelper {
	class HeaderPanel : public Panel
	{
	public:
		HeaderPanel() = default;
		virtual ~HeaderPanel() = default;
		virtual void Initialize(const char* id, const char* icon) override;
		virtual void Draw() override;
	};
}
