#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "string_manipulations.h"
#include "check.h"
#define MAX_SIZE 200


void go(char* input_command)
{
    char* new_path = malloc(sizeof(char) * MAX_SIZE);
    char* current_dir = malloc(sizeof(char) * MAX_SIZE);

    if(check_path(input_command, "go "))
    {
        strcpy(new_path, extract_string(input_command, "go "));
        trim_front_spaces(new_path);

    chdir(new_path);
    _getcwd(current_dir, MAX_SIZE);
    printf("Your current directory is changed: %s\n", current_dir);
    }
    free(current_dir);
    free(new_path);
    return;
}
