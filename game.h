#ifndef  __GAME__
#define  __GAME__

#include <stdbool.h>

#include "game.h"
#include "color.h"
#include "letter.h"
#include "render.h"

#define NUMBER_OF_LETTERS_IN_WORD 5
#define NUMBER_OF_GUESSES 5
#define NUMBER_OF_CORRECT_WORDS 1000

void game_init();
void init_table_sprite();
void handle_win();
void handle_lose();
void handle_wrong_word(struct Letter* wrongWord);
void handle_write_word();
void set_keys_colors(struct Letter* letters);
void add_word_to_guessed_words(struct Letter* word);
void set_word_letters_colors();

void handle_keybord_key_letter_prees(char key);
void handle_keybord_delete();
void handle_keybord_enter();

bool handle_find_char_in_word_and_it(char c, char* word);
void set_correct_word();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, int Button, int action, int modifier);

void handle_enter();
void handle_delete();


void add_letter_to_guessed_words(const char Letter);
bool check_if_letter_in_wrong_letters(char Letter);


extern struct Letter guessed_words[NUMBER_OF_GUESSES][NUMBER_OF_LETTERS_IN_WORD];

#endif //  __GAME__