#include "CentralDockingSpace.h"

#include <string>

#include "src/Core/Application.h"
#include "src/Utils/Constants.h"
#include "src/Core/Application.h"
#include "vendor/imgui-docking/imgui.h"
#include "vendor/imgui-docking/imgui_internal.h"

namespace PoeHelper {
	ImGuiID dockspaceID = 0;
	bool dockspaceBuild = false;
	std::string dockspaceName = std::string(POE_HELPER_DOCKSPACE_ID);
	std::string dockspaceBeginName = std::string(POE_HELPER_DOCKSPACE_BEGIN_ID);

	void CentralDockingSpace::Draw()
	{
		dockspaceID = ImGui::GetID(dockspaceName.c_str());
		const ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;
		ImGuiWindowFlags windowFlags = 0;
		windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
		windowFlags |= ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;
		windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;;
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		const ImVec2 dockspaceSize = ImVec2(viewport->WorkSize.x,
			viewport->WorkSize.y
			- Application::GetInstance().GetWindow().GetImGuiLayer()->m_HeaderSize
			- Application::GetInstance().GetWindow().GetImGuiLayer()->m_FooterSize);
		const ImVec2 dockspacePos = ImVec2(viewport->WorkPos.x,
			viewport->WorkPos.y
			+ Application::GetInstance().GetWindow().GetImGuiLayer()->m_HeaderSize);
		ImGui::SetNextWindowPos(dockspacePos);
		ImGui::SetNextWindowSize(dockspaceSize);
		ImGui::Begin(POE_HELPER_DOCKSPACE_BEGIN_ID, NULL, windowFlags);
		ImGui::DockSpace(dockspaceID, ImVec2(0, 0), dockspaceFlags);
		ImGui::End();
		if (!dockspaceBuild)
		{
			BuildDockspace();
		}
	}
	void CentralDockingSpace::BuildDockspace()
	{
		ImVec2 screenSize(Application::GetInstance().GetWindow().GetWidth(),
			Application::GetInstance().GetWindow().GetHeight() - POE_HELPER_FOOTER_HIEGHT);
		ImGui::DockBuilderRemoveNode(dockspaceID);
		const ImGuiDockNodeFlags dockNodeFlags = ImGuiDockNodeFlags_DockSpace;
		ImGui::DockBuilderAddNode(dockspaceID, dockNodeFlags);
		ImGui::DockBuilderSetNodeSize(dockspaceID, screenSize);

		ImGuiID dockMainID = dockspaceID;
		ImGuiID mainPanelID = ImGui::DockBuilderSplitNode(dockspaceID, ImGuiDir_Up, 0.5f, NULL, &dockspaceID);

		ImGui::DockBuilderDockWindow(POE_HELPER_ID_DOCK_MAIN, dockMainID);
		ImGui::DockBuilderDockWindow(ID_CONFIGURATION, dockspaceID);

		ImGui::DockBuilderFinish(dockspaceID);
		dockspaceBuild = true;
	}
}
