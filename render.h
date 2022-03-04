#ifndef __RENDER__
#define __RENDER__

#include"shaders.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1200

void render_init();
void render_update();

extern GLFWwindow* window;
	
#endif // !__RENDER__