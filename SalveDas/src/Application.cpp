#include "Application.h"

namespace SalveDas
{
	Application::Application()
		: window()
	{
		SalveDas::Logging::NewLogger("ENGINE");

		SalveDas::Logging::PrintLogger("ENGINE", 5000, 0);
		SalveDas::Logging::PrintLogger("ENGINE", "WARN", 1);
		SalveDas::Logging::PrintLogger("ENGINE", "INFO", 2);
	}
	Application::~Application()
	{
	}
	void Application::RunApp()
	{
		while (window.IsOpen() != -2)
		{
			window.RenderFrame();

			window.PollEvents();
		}
	}
}
