#include "HelloTriangle.h"

void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}

MYWINMAIN {
	std::unique_ptr<HelloTriangle> openGLApp(new HelloTriangle);
	openGLApp->init("HelloTriangle - Mawi1e", 1080, 920, GLFWKeyCallback);
	openGLApp->update();
}