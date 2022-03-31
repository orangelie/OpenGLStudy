#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "glfw3")

#include <Windows.h>

#include "glm.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <memory>

#define THROWF(n, e) if(n == 0) throw std::runtime_error(e)
#define DOTHROW (0)
#define MYWINMAIN int __stdcall WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)

class OpenGLApp {
public:
	OpenGLApp();
	~OpenGLApp();

	OpenGLApp(const OpenGLApp&) = delete;
	OpenGLApp& operator=(const OpenGLApp&) = delete;

	virtual void init(const char*, int, int, GLFWkeyfun);
	void update();

protected:
	virtual void startup();
	virtual void draw();
	virtual void destroy();

	GLfloat m_BackBufferColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	int m_ScreenWidth, m_ScreenHeight;
	int m_DisplayWidth, m_DisplayHeight;
	GLFWwindow* m_GLFWWindow = nullptr;

private:

private:

};

namespace Mawi1e {
	void M1EErrorCallback(int error, const char* descriptor);
}