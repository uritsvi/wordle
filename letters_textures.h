#ifndef __LETERS__TEXTURES_STRUCT__
#define __LETERS__TEXTURES_STRUCT__

#include <glad/glad.h>

#include "vectors.h"

struct letterTexture 
{
	struct minMaxVec2 placeInFontTexture;
};

struct letterTexture get_letter_texture(char c);

#endif // __LETERS__TEXTURES_STRUCT__