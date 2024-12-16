#pragma once

#include <GLFW/glfw3.h>
#include "glCore.h"

namespace SalveDas
{
	class Window
	{
	public:
		SALVE_DAS_GL_API Window();
		SALVE_DAS_GL_API ~Window();

		SALVE_DAS_GL_API void RenderFrame();
		SALVE_DAS_GL_API void PollEvents();
		SALVE_DAS_GL_API int IsOpen();
	private:
		GLFWwindow* m_window;
	};

}
