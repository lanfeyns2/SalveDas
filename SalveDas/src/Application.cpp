#include "Application.h"

namespace SalveDas
{
	Application::Application()
		: window()
	{
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
