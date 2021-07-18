#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200
char* read_from_stdin(char* buffer)
{
    if (fgets(buffer, MAX_SIZE, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[--len] = '\0';
        return strcmp(buffer, "") == 0 ? NULL : buffer;
    }
    return NULL;
}
