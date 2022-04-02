#include<stdio.h>
#include<stdlib.h>

#include "render.h"
#include "opengl_data_arrays.h"
#include "render_manager.h"
#include "texture.h"

GLFWwindow* window;

void render_init()
{
	int ret;

	ret = glfwInit();
	if (ret != GLFW_TRUE)
	{
		printf("glfwInit failed\n");
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "window 1", NULL, NULL);
	if (window == NULL) 
	{
		printf("Can't crate glfw window");
		exit(1);
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();
	
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	create_shaders_program("vertexShader.txt" , "fragmentShader.txt");

	init_data_arrays();
	init_renderd_textures();
}

void render_update()
{
	if (glfwWindowShouldClose(window))
		exit(0);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	use_shaders_program();

	update_renderd_textures();
	
	glfwSwapBuffers(window);
	glfwPollEvents();
}
