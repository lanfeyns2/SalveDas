#include "Application.h"

namespace SalveDas
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::RunApp()
	{
		while (true)
		{
			engineStack.RenderStack();
		}
	}
}
