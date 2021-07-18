#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#define MAX_SIZE 200

void current_directory()
{
    char* current_dir = malloc(sizeof(char) * MAX_SIZE);
    _getcwd(current_dir, MAX_SIZE);
    printf("Your current directory: %s\n", current_dir);
    free(current_dir);
    return;
}
