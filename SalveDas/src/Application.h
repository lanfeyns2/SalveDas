#pragma once
#include "LayerStack.h"
#include "Core.h"
#include "src/Window.h"
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace SalveDas
{
	class Application
	{
	public:
		SALVE_DAS_API Application();
		SALVE_DAS_API ~Application();

		SALVE_DAS_API void RunApp();

		SalveDas::LayerStack engineStack;
		Window window;
	};
}

