#pragma once
#include <string>

namespace PoeHelper {
	class FileUtils
	{
	public:
		static std::string GetAbsolutePath(const std::string pathFromExecutable);
	};
}
