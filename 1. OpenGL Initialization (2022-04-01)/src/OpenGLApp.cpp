#include "OpenGLApp.h"

OpenGLApp::OpenGLApp() {
}

OpenGLApp::~OpenGLApp() {
	destroy();
}

void OpenGLApp::init(const char* windowName, int screenWidth, int screenHeight, GLFWkeyfun keyCallbackFunc) {
	startup();

	m_DisplayWidth = screenWidth;
	m_DisplayHeight = screenHeight;

	// GLFW Initialization
	THROWF(glfwInit(), "@@@ Erorr: glfwinit");

	// GLFW Error Callback
	glfwSetErrorCallback(Mawi1e::M1EErrorCallback);

	// GLFW WindowHINT
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	// Create a GLFW Window
	m_GLFWWindow = glfwCreateWindow(screenWidth, screenHeight, windowName, nullptr, nullptr);
	//glfwSetWindowPos(window, )

	if (m_GLFWWindow == nullptr) {
		glfwTerminate();
		THROWF(DOTHROW, "@@@ Error: glfwCreateWindow");
	}

	// BUILDING INTERVAL FOR SCREEN SETTINGS
	glfwMakeContextCurrent(m_GLFWWindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);

	glfwSetKeyCallback(m_GLFWWindow, keyCallbackFunc);
}

void OpenGLApp::update() {
	// Rendering !
	while (!glfwWindowShouldClose(m_GLFWWindow)) {
		// input
		glfwPollEvents();

		// viewport
		glViewport(0, 0, m_DisplayWidth, m_DisplayHeight);

		// clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glClearColor(m_BackBufferColor[0], m_BackBufferColor[1], m_BackBufferColor[2], m_BackBufferColor[3]);

		// draw
		draw();

		// swapChain
		glfwSwapBuffers(m_GLFWWindow);
	}
}

void OpenGLApp::draw() {

}

void OpenGLApp::destroy() {
	// Destroy
	glfwDestroyWindow(m_GLFWWindow);
	glfwTerminate();
}

void OpenGLApp::startup() {
	m_ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	m_ScreenHeight = GetSystemMetrics(SM_CXSCREEN);
}

namespace Mawi1e {
	void M1EErrorCallback(int error, const char* descriptor) {
		throw std::runtime_error(descriptor);
	}
}