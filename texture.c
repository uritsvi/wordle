#include <stdbool.h>
#include <string.h>
#include <stb/stb_Image.h>

#include "shaders.h"
#include "texture.h"
#include "opengl_data_arrays.h"

GLuint texture;

char* last_path = 0;

void set_texture_path(const char* path, GLenum textureSlot)
{
	if (last_path != 0 && strcmp(path, last_path) == 0)
	{
		return;
	}

	stbi_set_flip_vertically_on_load(true);

	int textureWidth, textureHeight, textureNumColors;
	unsigned char* bytes = stbi_load(path, &textureWidth, &textureHeight, &textureNumColors, 0);
	if (!bytes)
	{
		printf("Error loading file '%s'\n", path);
		exit(1);
	}

	glGenTextures(1, &texture);
	glActiveTexture(textureSlot);

	bind_texture();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth , textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	last_path = _strdup(path);
}

void set_texture_color(struct vec3 color)
{
	GLuint colorUniform = glGetUniformLocation(shadersProgram, "color");
	glUniform3f(colorUniform, color.x, color.y, color.z);
}

void set_texture_position(struct vec2 position)
{
	GLuint positionUniform = glGetUniformLocation(shadersProgram, "position");
	glUniform3f(positionUniform, position.x / 100, position.y / 100, 0);
}

void set_texture_scale(struct vec2 scale) 
{
	set_VBO_scale(scale);
}

void set_texture_coords(struct minMaxVec2 thisTexturePlaceInLoadTexture) 
{
	set_VBO_texture_coords(thisTexturePlaceInLoadTexture);
}

void draw_textures()
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)0);
}

void bind_texture()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}
