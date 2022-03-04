#ifndef __READ__FILES__
#define __READ__FILES__

#include "game.h"

void read_txt_file_into_char(const char* fileName, char *buffer);
void read_txt_files_into_arrays(const char* fileName, char src_buffer[][NUMBER_OF_LETTERS_IN_WORD]);

#endif // !__READ__FILES__
