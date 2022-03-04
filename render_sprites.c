#include <stdlib.h>
#include <string.h>
#include "stdio.h"

#include "render_sprites.h"
#include "texture.h"
#include "color.h"

#define numOfCellsInArray 100

struct sprite* sprites[numOfCellsInArray] = { NULL };
int  numOfUsedCells = 0;

void add_sprite_to_render_list(struct sprite* sprite)
{
	sprites[numOfUsedCells++] = sprite;
}

void render_sprites_update()
{
	for (int i = 0; i < numOfUsedCells; i++)
	{
		set_texture_path(sprites[i]->texturePath, 0);
		
		struct vec2 position = sprites[i]->position;
		struct vec2 scale = sprites[i]->scale;
		struct vec3 color = sprites[i]->color;
		struct minMaxVec2 textureCoords = sprites[i]->place_in_texture;
		
		set_texture_position(position);
		set_texture_scale(scale);
		set_texture_color(color);
		set_texture_coords(textureCoords);
		
		draw_textures();	
	}
}
