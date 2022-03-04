#ifndef __TEXTURE__
#define __TEXTURE__

#include <glad/glad.h>

#include "vectors.h"
#include "shaders.h"

void set_texture_path(const char* path , GLenum textureSlot);
void set_texture_color(struct vec3 color);
void set_texture_position(struct vec2 position);
void set_texture_scale(struct vec2 scale);
void set_texture_coords(struct minMaxVec2 thisTexturePlaceInLoadTexture);
void draw_textures();
void bind_texture();

#endif // !__TEXTURE__
