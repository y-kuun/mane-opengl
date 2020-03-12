// -*- coding: gb18030 -*-

#include <windows.h>
#include <synchapi.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

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

void draw();
void init();

#if 0
#pragma comment( linker, "/subsystem:windows" )

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

int main(int argc, char** argv) {
	init();
	while (true)
	{
		draw();
		Sleep(1000);
	}
}
#endif

void draw()
{
	std::cout << "Frame updated!!!" << std::endl;
}

void init()
{
	// init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}
