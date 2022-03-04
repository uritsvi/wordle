#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "keybord.h"
#include "render_sprites.h"
#include "color.h"
#include "buttons.h"
#include "letters_textures.h"
#include "game.h"

#define NUM_OF_KEYS 26

#define DISTANCE_BETWEEN_LETTERS_X 12.5
#define DISTANCE_BETWEEN_LETTERS_Y 10

#define POSITION_X -90.0f
#define POSITION_Y -50.0f

struct sprite* keys[100];

void init_keyboard()
{
	init_keybord_letters();
	init_delete();
	init_enter();
}

void init_keybord_letters()
{
	for (int i = 0; i < NUM_OF_KEYS; i++)
	{
		struct sprite* sprite = (struct sprite*)malloc(sizeof(struct sprite));
		if (!sprite)
		{
			printf("Not enough memory\n");
			exit(1);
		}

		char curent_charecter = i + 'A';

		struct vec3 white_color = WHITE;
		sprite->color = white_color;

		if (i - 13 >= 0)
		{
			struct vec2 position = { .x = POSITION_X + (i - 13.0f) * DISTANCE_BETWEEN_LETTERS_X , .y = POSITION_Y - DISTANCE_BETWEEN_LETTERS_Y };
			sprite->position = position;
		}
		else
		{
			struct vec2 position = { .x = POSITION_X + i * DISTANCE_BETWEEN_LETTERS_X , .y = POSITION_Y };
			memcpy(&sprite->position, &position, sizeof(position));
		}

		struct vec2 scale = { .x = 5.5, .y = 4.0f };
		sprite->scale = scale;

		struct minMaxVec2 place_in_texture = get_letter_texture(curent_charecter).placeInFontTexture;
		sprite->place_in_texture = place_in_texture;

		sprite->texturePath = _strdup("defalut font.png");

		add_sprite_to_render_list(sprite);

		struct Button* Button = (struct Button*)malloc(sizeof(struct Button));
		if (!Button)
		{
			printf("Not enough memory\n");
			exit(1);
		}
		Button->sprite = sprite;
		Button->onPressButton = handle_keybord_key_letter_prees;
		Button->data = curent_charecter;

		add_button_to_array(Button);
		keys[i] = sprite;
	}
}

void init_enter()
{
	struct sprite* delete_button_spite = (struct sprite*)malloc(sizeof(struct sprite));

	struct vec3 color = WHITE;
	memcpy(&delete_button_spite->color, &color, sizeof(color));

	struct vec2 position = { .x = 85 , .y = -50 };
	memcpy(&delete_button_spite->position, &position, sizeof(position));

	struct vec2 scale = { .x = 5.5f , .y = 4.0f };
	memcpy(&delete_button_spite->scale, &scale, sizeof(scale));

	struct minMaxVec2 place_in_texture = { .xMax = 1.0f, .xMin = 0.0f, .yMax = 1.0, .yMin = 0.0f };
	memcpy(&delete_button_spite->place_in_texture, &place_in_texture, sizeof(place_in_texture));

	delete_button_spite->texturePath = _strdup("delete.png");

	struct Button* Button = (struct Button*)malloc(sizeof(struct Button));
	if (!Button)
	{
		printf("Not enough memory\n");
		exit(1);
	}
	Button->sprite = delete_button_spite;
	Button->onPressButton = handle_keybord_delete;

	add_button_to_array(Button);
}

void init_delete()
{
	struct sprite* eneter_button_spite = (struct sprite*)malloc(sizeof(struct sprite));

	struct vec3 color = WHITE;
	memcpy(&eneter_button_spite->color, &color, sizeof(color));

	struct vec2 position = { .x = 85 , .y = -60 };
	memcpy(&eneter_button_spite->position, &position, sizeof(position));

	struct vec2 scale = { .x = 5.5f , .y = 4.0f };
	memcpy(&eneter_button_spite->scale, &scale, sizeof(scale));

	struct minMaxVec2 place_in_texture = { .xMax = 1.0f, .xMin = 0.0f, .yMax = 1.0, .yMin = 0.0f };
	memcpy(&eneter_button_spite->place_in_texture, &place_in_texture, sizeof(place_in_texture));

	eneter_button_spite->texturePath = _strdup("enter.png");

	struct Button* Button = (struct Button*)malloc(sizeof(struct Button));
	if (!Button)
	{
		printf("Not enough memory\n");
		exit(1);
	}
	Button->sprite = eneter_button_spite;
	Button->onPressButton = handle_keybord_enter;

	add_button_to_array(Button);
}

void set_key_color(struct vec3 color, char key) 
{
	struct vec3 defalute_color = WHITE;
	if (keys[key - 'A']->color.x == defalute_color.x && keys[key - 'A']->color.y == defalute_color.y && keys[key - 'A']->color.z == defalute_color.z)
	{
		keys[key - 'A']->color = color;
	}
}
