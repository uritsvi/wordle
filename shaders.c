#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shaders.h"
#include "readFiles.h"

GLuint shadersProgram;

#define SRC_LEN 5000
char vertex_src[SRC_LEN] = { 0 };
char fragment_src[SRC_LEN] = { 0 };
const char* src_files[1];
GLuint vertexShader, fragmentShader;

void create_shaders_program(const char *vertexShaderSourceFileName , const char* fragmentShaderSourceFileName)
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	src_files[0] = vertex_src;
	read_txt_file_into_char(vertexShaderSourceFileName, vertex_src);
	glShaderSource(vertexShader, 1, src_files, NULL);

	src_files[0] = fragment_src;
	read_txt_file_into_char(fragmentShaderSourceFileName, fragment_src);
	glShaderSource(fragmentShader, 1, src_files, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	shadersProgram = glCreateProgram();

	glAttachShader(shadersProgram, vertexShader);
	glAttachShader(shadersProgram, fragmentShader);

	glLinkProgram(shadersProgram);
	int ret;
	glGetProgramiv(shadersProgram, GL_LINK_STATUS, &ret);
	if (ret != GL_TRUE)
	{
		printf("Link failed\n");
		exit(1);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void use_shaders_program() 
{
	glUseProgram(shadersProgram);
}

