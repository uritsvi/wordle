#ifndef __RENDER__TEXT__
#define __RENDER__TEXT__

#include "vectors.h"

struct text 
{
	char* text;
	struct vec3 color;

	struct vec2 position;
	struct vec2 scale;
};

void init_render_text();
void add_text_to_renderd_texts(struct text* text);
void update_render_text();

#endif // !__RENDER__TEXT__
