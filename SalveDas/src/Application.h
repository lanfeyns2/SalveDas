#pragma once
#include "LayerStack.h"
#include "Core.h"
#include "src/Window.h"
#include <iostream>

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

