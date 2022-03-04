#include "render_manager.h"
#include "write_game_guessed_words_array.h"
#include "render_sprites.h"
#include "render_sprites.h"
#include "render_text.h"
#include "texture.h"
#include "buttons.h"

void init_renderd_textures()
{
	init_render_text();
}

void update_renderd_textures() 
{
	render_sprites_update();
	update_render_text();
	update_write_guss_game_words_array_to_screen();
}