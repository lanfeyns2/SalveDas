#include "Application.h"

namespace SalveDas
{
	Application::Application()
		: window()
	{

		auto Engine = spdlog::stdout_color_mt("ENGINE");
		auto Console = spdlog::stdout_color_mt("CONSOLE");

		// Set patterns with colors
		Engine->set_pattern("%^[%n %T]:[%l]:%$ %v");
		Console->set_pattern("%^[%n %T]:[%l]:%$ %v");
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
