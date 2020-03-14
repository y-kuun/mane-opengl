// -*- coding: utf-8 -*-
// msbuild.exe mane-opengl.sln -p:Configuration=Release -p:Platform=x64

#include <windows.h>
#include <synchapi.h>
#include <iostream>

#include "mane.h"
#include "main_app.h"

void draw();
MANE_RESULT init();

#if 0
LRESULT CALLBACK WindowProc(
    _In_ HWND   hwnd,
    _In_ UINT   uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
)
{
	LRESULT result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    return result;
}

// #pragma comment( linker, "/subsystem:windows" )
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
)
{

    WNDCLASSW WindowClass = {0};
    WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hInstance = hInstance;
    // WindowClass.hIcon = ;
    WindowClass.lpszClassName = TEXT("Mane OpenGL");

		
    if(RegisterClassW(&WindowClass))
    {
        HWND WindowHandle = CreateWindowExW(
            0, WindowClass.lpszClassName, TEXT("欢迎来到 Mane OpenGL"), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0
			);

		if(WindowHandle)
		{
			while(true)
			{
				MSG Message;
				while(PeekMessage(&Message, 0, 0, 0, PM_REMOVE))
				{
					switch(Message.message)
					{
						case WM_QUIT:
						case WM_SYSKEYDOWN:
						case WM_SYSKEYUP:
						case WM_KEYDOWN:
						case WM_KEYUP:
						// {
						// 	uint32_t VKCode = (uint32_t)Message.wParam;
						// 	bool WasDown = ((Message.lParam & (1 << 30)) != 0);
						// 	bool IsDown = ((Message.lParam & (1 << 31)) == 0);
						// }
						default:
						{
							TranslateMessage(&Message);
							DispatchMessageW(&Message);
						}
					}
				}
				draw();
				Sleep(1000);
			}
		}
		else
		{
			// log
		}
    }
	else
	{
		// log
	}
    return 0;
}
#else

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(int argc, char** argv)
{
	init();
	mane_global::g_window_ = glfwCreateWindow(mane_const::MANE_DEFAULT_WIDTH, mane_const::MANE_DEFAULT_HEIGHT,
											  "欢迎来到 Mane OpenGL !!!", NULL, NULL);
	if (mane_global::g_window_ == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(mane_global::g_window_);
	glfwSetFramebufferSizeCallback(mane_global::g_window_, framebuffer_size_callback);	

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" <<std::endl ;
		return MANE_FAILED;
	}
	std::cout << "Main Loop Entry!!!" << std::endl;
	
	while(!glfwWindowShouldClose(mane_global::g_window_))
	{
		processInput(mane_global::g_window_);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(mane_global::g_window_);
		glfwPollEvents();
		
	}
	glfwTerminate();
	return 0;
}
#endif

void draw()
{
	std::cout << "Frame updated!!!" << std::endl;
}

MANE_RESULT init()
{
	// init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	return MANE_OK;
}
