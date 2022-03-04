#ifndef __RENDER__SPRITES__
#define __RENDER__SPRITES__

#include "vectors.h"

struct sprite
{
	struct vec3 color;
	struct vec2 position;
	struct vec2 scale;
	struct minMaxVec2 place_in_texture;

	char* texturePath;
};
 
void add_sprite_to_render_list(struct sprite *sprite);
void render_sprites_update();

#endif // !__RENDER__OBJECTS__
