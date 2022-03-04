#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "game.h"
#include "render_sprites.h"
#include "render_text.h"
#include "buttons.h"
#include "keybord.h"
#include "readFiles.h"

char correct_word[NUMBER_OF_LETTERS_IN_WORD+1];
char correct_words[NUMBER_OF_CORRECT_WORDS][NUMBER_OF_LETTERS_IN_WORD+1];
struct Letter guessed_words[NUMBER_OF_GUESSES][NUMBER_OF_LETTERS_IN_WORD] = { 0 };
int curent_index_guessed_words = 0;
int curent_index_letter_in_guessed_words = 0;
char wrong_letters[NUMBER_OF_LETTERS_IN_WORD * NUMBER_OF_GUESSES] = { 0 };
int curent_index_wrong_letters = 0;													
int numTriesLeft = NUMBER_OF_GUESSES;

bool alredyWon = false;


void set_correct_word()
{
	int num_of_lines = 661;
	read_txt_files_into_arrays("common five letters words.txt", correct_words);

	srand(time(NULL));
	int randomWordIndex = rand() % num_of_lines + 1;
	strcpy(correct_word, correct_words[randomWordIndex]);
}

bool handle_find_char_in_word_and_it(char c, char* word)
{
	for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++)
	{
		char current_letter = tolower(word[i]);
		char actual_char = tolower(c);
		if (current_letter == actual_char)
		{
			word[i] = 0;
			return true;
		}
	}
	return false;
}

void set_word_letters_colors()
{
	char letters_not_colored_in_correct_word[NUMBER_OF_LETTERS_IN_WORD] = { 0 };
	strncpy(letters_not_colored_in_correct_word, correct_word, NUMBER_OF_LETTERS_IN_WORD);

	for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++)
	{
		char current = tolower(letters_not_colored_in_correct_word[i]);
		char expected = tolower(guessed_words[curent_index_guessed_words][i].character);
		if (current == expected)
		{
			struct vec3 green_color = GREEN;
			guessed_words[curent_index_guessed_words][i].color = green_color;
			letters_not_colored_in_correct_word[i] = 0;
		}
	}

	for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++)
	{
		if (handle_find_char_in_word_and_it(guessed_words[curent_index_guessed_words][i].character, letters_not_colored_in_correct_word) == true)
		{
			struct vec3 yellow_color = YELLOW;
			guessed_words[curent_index_guessed_words][i].color = yellow_color;
		}
		else
		{
			struct vec3 green_color = GREEN;
			if (guessed_words[curent_index_guessed_words][i].color.x != green_color.x && guessed_words[curent_index_guessed_words][i].color.y != green_color.z && guessed_words[curent_index_guessed_words][i].color.x != green_color.z)
			{
				struct vec3 grey_color = GREY;
				guessed_words[curent_index_guessed_words][i].color = grey_color;
			}
		}
	}
}

void set_keys_colors(struct Letter* letters)
{
	for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++) 
	{
		set_key_color(letters[i].color, letters[i].character);
	}
}

void add_word_to_guessed_words(struct Letter* word)
{
	struct Letter newly_added_word[NUMBER_OF_LETTERS_IN_WORD];
	for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++)
	{
		newly_added_word[i].character = word[i].character;
	}

	set_word_letters_colors(newly_added_word);
	set_keys_colors(guessed_words[curent_index_guessed_words]);
}

void handle_wrong_word(struct Letter* wrongWord)
{
	add_word_to_guessed_words(wrongWord);
	curent_index_guessed_words++;
}

void handle_write_word() 
{
	for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++)
	{
		struct vec3 color = GREEN;
		guessed_words[curent_index_guessed_words][i].color = color;
	}
}

void handle_keybord_key_letter_prees(char key)
{
	add_letter_to_guessed_words(key);
}

void handle_keybord_delete()
{
	handle_delete();
}

void handle_keybord_enter()
{
	handle_enter();
}

bool check_if_letter_in_wrong_letters(char Letter)
{
	for (int i = 0; i < sizeof(wrong_letters) / sizeof(char); i++) 
	{
		if (wrong_letters[i] != 0)
		{
			char wrong_letter = tolower(wrong_letters[i]);
			char letter_lc = tolower(Letter);
			if (wrong_letter == letter_lc)
			{
				return true;
			}
		}
		else 
		{
			return false;
		}
	}
	return false;
}

void add_letter_to_guessed_words(const char Letter)
{
	if (curent_index_letter_in_guessed_words < 5 && Letter >= 'A' && Letter  <= 'Z')
	{
		struct vec3 color = WHITE;
		guessed_words[curent_index_guessed_words][curent_index_letter_in_guessed_words].character = Letter;
		guessed_words[curent_index_guessed_words][curent_index_letter_in_guessed_words].color = color;
		curent_index_letter_in_guessed_words++;
	}
}

void handle_lose()
{
	struct text* you_lost_text = (struct text*)malloc(sizeof(struct text));
	
	struct vec3 color = RED;
	memcpy(&you_lost_text->color, &color, sizeof(color));

	struct vec2 position = { .x = -30 , .y = -30 };
	memcpy(&you_lost_text->position, &position, sizeof(position));

	struct vec2 scale = { .x = 5 , .y = 3 };
	memcpy(&you_lost_text->scale, &scale, sizeof(scale));

	you_lost_text->text = _strdup("you lost");

	add_text_to_renderd_texts(you_lost_text);
}
void handle_win()
{
	alredyWon = true;
	
	struct text* you_won_text = (struct text*)malloc(sizeof(struct text));

	struct vec3 color = GREEN;
	memcpy(&you_won_text->color, &color, sizeof(color));

	struct vec2 position = { .x = -30 , .y = -30 };
	memcpy(&you_won_text->position, &position, sizeof(position));

	struct vec2 scale = { .x = 5 , .y = 3 };
	memcpy(&you_won_text->scale, &scale, sizeof(scale));

	you_won_text->text = _strdup("you won");
	
	add_text_to_renderd_texts(you_won_text);
}

void game_init()
{
	set_correct_word();
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_callback);

	init_table_sprite();
	init_keyboard();
}

void init_table_sprite() 
{
	struct sprite* table_sprite = (struct sprite*)malloc(sizeof(struct sprite));

	struct vec3 color = WHITE;
	memcpy(&table_sprite->color, &color, sizeof(color));

	struct vec2 position = { .x = 0 , .y = 20 };
	memcpy(&table_sprite->position, &position, sizeof(position));

	struct vec2 scale = { .x = 75 , .y = 60 };
	memcpy(&table_sprite->scale, &scale, sizeof(scale));

	struct minMaxVec2 place_in_texture = { .xMax = 1.0f, .xMin = 0.0f, .yMax = 1.0, .yMin = 0.0f };
	memcpy(&table_sprite->place_in_texture, &place_in_texture , sizeof(place_in_texture));

	table_sprite->texturePath = _strdup("grid.png");

	add_sprite_to_render_list(table_sprite);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ENTER) 
	{
		handle_enter();
	}
	else if (key == GLFW_KEY_BACKSPACE) 
	{
		handle_delete();
	}
	else if(action == GLFW_PRESS)
	{
		if (numTriesLeft >= 0 && !alredyWon && check_if_letter_in_wrong_letters(key) == false) 
		{
			add_letter_to_guessed_words(key);
		}
	}
}

void handle_enter() 
{
	if (guessed_words[curent_index_guessed_words][NUMBER_OF_LETTERS_IN_WORD - 1].character != 0)
	{
		char word[NUMBER_OF_LETTERS_IN_WORD + 1];

		for (int i = 0; i < NUMBER_OF_LETTERS_IN_WORD; i++)
		{
			word[i] = guessed_words[curent_index_guessed_words][i].character;
		}
		word[NUMBER_OF_LETTERS_IN_WORD] = '\0';

		if (stricmp(word, correct_word) == 0)
		{
			handle_write_word();
			handle_win();
		}
		else
		{
			handle_wrong_word(guessed_words[curent_index_guessed_words]);
			numTriesLeft--;
		}

		if (numTriesLeft == 0)
		{
			handle_lose();
		}
		
		curent_index_letter_in_guessed_words = 0;
	}
}
void handle_delete() 
{
	if (!alredyWon)
	{
		curent_index_letter_in_guessed_words--;

		struct vec3 white_color = WHITE;
		guessed_words[curent_index_guessed_words][curent_index_letter_in_guessed_words].character = 0;
		guessed_words[curent_index_guessed_words][curent_index_letter_in_guessed_words].color = white_color;
	}
}

void mouse_callback(GLFWwindow* window, int Button, int action, int modifier)
{
	if (action == GLFW_PRESS && Button == GLFW_MOUSE_BUTTON_1) 
	{
		double mose_x_pos, mose_y_pos;
		glfwGetCursorPos(window, &mose_x_pos, &mose_y_pos);

		mose_x_pos = (mose_x_pos / 4) - 100;
		mose_y_pos = (mose_y_pos / 6) - 100;

		on_mouse_click(mose_x_pos, -mose_y_pos);
	}
}
