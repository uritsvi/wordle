#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "readFiles.h"

void read_txt_file_into_char(const char* fileName, char* src_buffer)
{
	char line[80];
	FILE* file;
	fopen_s(&file, fileName, "r");
	while (fgets(line, 79, file))
	{
		strcat(src_buffer, line);
	}

	fclose(file);
}

void read_txt_files_into_arrays(const char* fileName, char src_buffer[][NUMBER_OF_LETTERS_IN_WORD+1])
{
	char line[80];
	FILE* file;
	int line_no = 0;
	fopen_s(&file, fileName, "r");
	while (fgets(line, 79, file))
	{
		line[5] = 0;
		strcpy(src_buffer[line_no++], line);
	}

	fclose(file);
}
