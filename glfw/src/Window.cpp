#include "Window.h"

namespace SalveDas
{
	Window::Window()
	{
		if (!glfwInit())
			throw("CANNONT INIT WINDOW");

		/* Create a windowed mode window and its OpenGL context */
		m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!m_window)
		{
			glfwTerminate();
			throw("CANNOT MAKE WINDOW");
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(m_window);
	}
	Window::~Window()
	{
		glfwTerminate();
	}
	void Window::RenderFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(m_window);
	}
	void Window::PollEvents()
	{
		glfwPollEvents();
	}
	int Window::IsOpen()
	{
		return ~glfwWindowShouldClose(m_window);
	}
}