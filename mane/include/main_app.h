#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

/* const variables */

namespace mane_const
{
	const int MANE_DEFAULT_WIDTH = 1920;
	const int MANE_DEFAULT_HEIGHT = 1080;
}

namespace mane_global
{
	GLFWwindow* g_window_ = NULL;
}
