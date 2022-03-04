#include "color.h"

struct vec3 get_color(enum color color) 
{
	if (color == red) 
	{
		struct vec3 Vcolor = { .x = 1.0f , .y = 0.0f , 0.0f };
		return Vcolor;
	}
	else if (color == yellow) 
	{
		struct vec3 Vcolor = { .x = 1.0f , .y = 1.0f , 0.0f };
		return Vcolor;
	}
	else if (color == green) 
	{
		struct vec3 Vcolor = { .x = 0.0f , .y = 1.0f , 0.0f };
		return Vcolor;
	}
	else if (color == white) 
	{
		struct vec3 Vcolor = { .x = 1.0f , .y = 1.0f , 1.0f };
		return Vcolor;
	}
}