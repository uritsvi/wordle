#ifndef __BUTTONS__
#define __BUTTONS__

#include "render_sprites.h"
#include "vectors.h"

struct Button 
{
	struct sprite* sprite;
	struct minMaxVec2 minMax;

	void (*onPressButton)(char data);

	char data;
};

void add_button_to_array(struct Button* Button);
void on_mouse_click(double mouse_pose_x , double mouse_pose_y);
void set_button_min_max(struct Button* Button);

#endif // !__BUTTONS__
