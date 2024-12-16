#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Core.h"

namespace SalveDas
{
	class SceneManager
	{
	public:
		SALVE_DAS_API SceneManager();
		SALVE_DAS_API ~SceneManager();

		SALVE_DAS_API void LoadScene(const char* name);
		SALVE_DAS_API void NewScene(const char* name);
		SALVE_DAS_API void SetProjectDirectory(const char* Directory);
	private:
		std::string m_projectDir;
	};
}

