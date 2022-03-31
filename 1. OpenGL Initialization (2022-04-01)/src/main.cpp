#include "HelloTriangle.h"

void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

MYWINMAIN {
	std::unique_ptr<HelloTriangle> openGLApp(new HelloTriangle);
	openGLApp->init("HelloTriangle - Mawi1e", 1080, 920, GLFWKeyCallback);
	openGLApp->update();
}