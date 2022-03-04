#include <stddef.h>
#include <string.h>

#include "render_text.h"
#include "texture.h"
#include "letters_textures.h"

#define numOfCellsInArray 20

struct text* renderdTexts[numOfCellsInArray] = { NULL };

int numOfFullCells = 0;

#define distanceBetweenLetters 10

void init_render_text() 
{

}

void add_text_to_renderd_texts(struct text* text)
{
	for (int i = 0; i < numOfCellsInArray; i++)
	{
		if (renderdTexts[i] == NULL)
		{
			renderdTexts[i] = text;

			numOfFullCells++;

			return;
		}
	}
}

void update_render_text() 
{
	set_texture_path("defalut font.png" , 0);

	for (int i = 0; i < numOfFullCells; i++) 
	{
		struct text* text = renderdTexts[i];
		
		set_texture_color(text->color);
		set_texture_scale(text->scale);

		for (int i = 0; i < strlen(text->text); i++) 
		{
			struct vec2 letterPosition = { .x = (i * distanceBetweenLetters) + text->position.x , text->position.y };

			set_texture_position(letterPosition);
			set_texture_coords(get_letter_texture(text->text[i]).placeInFontTexture);

			draw_textures();
		}
	}
}