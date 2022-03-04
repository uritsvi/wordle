#ifndef __SHADERS__
#define __SHADERS__

#include <stddef.h>
#include <glad/glad.h>

#include"vectors.h"

void create_shaders_program(const char* vertexShaderSource, const char* fragmentShaderSource);
void use_shaders_program();

extern GLuint shadersProgram;


#endif // !__SHADERS__
