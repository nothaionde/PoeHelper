#include <Windows.h>
#include "src/Core/Application.h"
#include "src/Utils/Constants.h"

class PoeHelperMain : public PoeHelper::Application
{
public:
	PoeHelperMain(const std::string name, uint32_t width, uint32_t height, bool decorated)
		: Application(name, width, height, decorated)
	{
	}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::unique_ptr<PoeHelperMain> app = 
		std::make_unique<PoeHelperMain>(POE_HELPER_APPLICATION_NAME, POE_HELPER_WIDTH, POE_HELPER_HEIGHT, POE_HELPER_WINDOW_RESIZABLE);
	app->Run();
}
