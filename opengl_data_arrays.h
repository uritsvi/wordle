#ifndef __OPENGL__DATA_ARRAYS__
#define __OPENGL__DATA_ARRAYS

#include <glad/glad.h>

#include "vectors.h"

void init_data_arrays();

void create_VAO();
void bind_VAO();
void VAO_linkAttrib(GLuint layout, GLuint numComponents, GLuint type, GLsizeiptr stride, void* offset);

void create_VBO();
void bind_VBO();
void set_VBO_vertices(GLfloat* vertices, GLsizeiptr size);
void set_VBO_scale(struct vec2 scale);
void set_VBO_texture_coords(struct minMaxVec2 textureCooords);
void get_renderd_object_xMix_xMax(struct minMaxVec2* minMaxVec2, struct sprite* sprite);

void create_EBO();
void bind_EBO();
void set_EBO_indices(GLuint* indices, GLsizeiptr size);

#endif // !__OPENGL__DATA_ARRAYS__