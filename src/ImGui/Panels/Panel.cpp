#include "Panel.h"

namespace PoeHelper {
	void Panel::Initialize(const char* id, const char* icon)
	{
		m_Id = id;
		m_Icon = icon;
		m_Title = id;
	}
}
