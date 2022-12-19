#include "include/io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *get_file_contents(const char *filepath)
{
    char *buffer = 0;
    long length;
    FILE *f;

    int length_f = strlen(filepath);
    if (filepath[length_f - 1] == 'z' && filepath[length_f - 2] == 'd' && filepath[length_f - 3] == 'i' && filepath[length_f - 4] == 'k' && filepath[length_f - 5] == '.')
    {
        f = fopen(filepath, "r");
        if (f)
        {
            fseek(f, 0, SEEK_END);
            length = ftell(f);
            fseek(f, 0, SEEK_SET);

            buffer = calloc(length, length);

            if (buffer)
                fread(buffer, 1, length, f);

            fclose(f);

            return buffer;
        }

        printf("Error reading file %s\n", filepath);
        exit(2);
    }

    else
    {
        printf("Filetype not supported.\n");
        exit(2);
    }
}