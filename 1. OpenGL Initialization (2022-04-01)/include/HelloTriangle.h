#pragma once

#include "OpenGLApp.h"

class HelloTriangle : public OpenGLApp {
public:
	HelloTriangle();
	~HelloTriangle();

	HelloTriangle(const HelloTriangle&) = delete;
	HelloTriangle& operator=(const HelloTriangle&) = delete;

	virtual void init(const char*, int, int, GLFWkeyfun) override;

protected:
	virtual void draw() override;

};