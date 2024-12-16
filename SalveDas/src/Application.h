#pragma once
#include "LayerStack.h"
#include "Core.h"

namespace SalveDas
{
	class Application
	{
	public:
		SALVE_DAS_API Application();
		SALVE_DAS_API ~Application();

		SALVE_DAS_API void RunApp();

		SalveDas::LayerStack engineStack;
	};
}

