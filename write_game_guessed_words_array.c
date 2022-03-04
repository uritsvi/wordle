#include "write_game_guessed_words_array.h"
#include "texture.h"
#include "letter.h"
#include "vectors.h"
#include "game.h"
#include "letters_textures.h"
#include "opengl_data_arrays.h"


#define DISTANCE_BETWEEN__LETTERS_IN_X 25.0f
#define DISTANCE_BETWEEN__LETTERS_IN_Y 15.0f

#define X_POSITION 52.25f
#define Y_POSITION -50.0f

void draw_leter(struct Letter Letter, struct vec2 position)
{
	struct letterTexture letterTexture = get_letter_texture(Letter.character);

	set_texture_color(Letter.color);

	set_texture_position(position);

	struct minMaxVec2 placeInFontTexture = letterTexture.placeInFontTexture;
	struct vec2 scale = { .x = 8.0f , .y = 5.0f };

	set_texture_scale(scale);
	set_texture_coords(placeInFontTexture);

	draw_textures();
}
void update_draw_chars_to_screen()
{
	for (int i = 0; i < NUMBER_OF_GUESSES; i++) 
	{
		for (int x = 0; x < NUMBER_OF_LETTERS_IN_WORD; x++)
		{
			if (guessed_words[i][x].character != 0)
			{
				struct vec2 letterPosition = { (x * DISTANCE_BETWEEN__LETTERS_IN_X) - X_POSITION , (i * -DISTANCE_BETWEEN__LETTERS_IN_Y) - Y_POSITION};
				draw_leter(guessed_words[i][x], letterPosition);
			}
		}
	}
}

void update_write_guss_game_words_array_to_screen()
{
	update_draw_chars_to_screen();
}
