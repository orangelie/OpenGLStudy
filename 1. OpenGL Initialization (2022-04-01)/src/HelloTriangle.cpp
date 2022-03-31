#include "HelloTriangle.h"

HelloTriangle::HelloTriangle() {

}

HelloTriangle::~HelloTriangle() {

}

void HelloTriangle::init(const char* windowName, int screenWidth, int screenHeight, GLFWkeyfun keyCallbackFunc) {
	OpenGLApp::init(windowName, screenWidth, screenHeight, keyCallbackFunc);

}

void HelloTriangle::draw() {

}