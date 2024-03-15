#include "FileUtils.h"
#include <windows.h>

namespace PoeHelper {
	std::string FileUtils::GetAbsolutePath(const std::string pathFromExecutable)
	{
		char exeFilePath[MAX_PATH];
		GetModuleFileName(NULL, exeFilePath, MAX_PATH);

		std::string exeDir = std::string(exeFilePath);
		size_t pos = exeDir.find_last_of("\\/");
		exeDir = exeDir.substr(0, pos + 1);

		std::string absolutePath = exeDir + pathFromExecutable;

		return absolutePath;
	}
}
