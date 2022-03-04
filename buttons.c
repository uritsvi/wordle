#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buttons.h"
#include "render.h"
#include "vectors.h"
#include "opengl_data_arrays.h"
#include "render_text.h"
#include "color.h"

#define ARRAY_LEN 100
struct Button* buttons[ARRAY_LEN] = {NULL};
int num_of_used_cells = 0;

void set_button_min_max(struct Button* Button) 
{
	get_renderd_object_xMix_xMax(&Button->minMax , Button->sprite);
}

void add_button_to_array(struct Button* Button) 
{
	set_button_min_max(Button);
	add_sprite_to_render_list(Button->sprite);

	buttons[num_of_used_cells] = Button;
	num_of_used_cells++;
}

void on_mouse_click(double mouse_pose_x, double mouse_pose_y)
{
	for (int i = 0; i < ARRAY_LEN; i++) 
	{
		if (buttons[i] != NULL) 
		{
			struct minMaxVec2 button_min_max = buttons[i]->minMax;

			if (mouse_pose_x >= button_min_max.xMin && mouse_pose_x <= button_min_max.xMax &&
				mouse_pose_y >= button_min_max.yMin && mouse_pose_y <= button_min_max.yMax)
			{
				buttons[i]->onPressButton(buttons[i]->data);
			}
		}
		else
		{
			return;
		}
	}
}
