#ifndef __KEYBORD__
#define __KEYBORD__

#include "vectors.h"

void init_keyboard();

void init_keybord_letters();
void init_enter();
void init_delete();

void set_key_color(struct vec3 color, char key);

#endif // ! __KEYBORD__
