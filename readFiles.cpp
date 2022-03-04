#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "readFiles.h"

void read_txt_file_into_char(const char* fileName, char *src_buffer) 
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