#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <direct.h>
#include "string_manipulations.h"
#define MAX_SIZE 200

int check_path(char* input_string, char* command)
{
    char* tmp = malloc(sizeof(char) * MAX_SIZE);
    strcpy(tmp, input_string);
    if (tmp != NULL)
        strcpy(tmp, extract_string(tmp, command));
    trim_front_spaces(tmp);

    DIR* dir = opendir(tmp);
    if (dir)
    {
        closedir(dir);
        return 1;
    }
    else if (ENOENT == errno)
        printf("Path is invalid. Check help in case you are using the command incorrectly.\n");
    else
        printf("An error occurred. Please check help and try again.\n");
    free(tmp);
    return 0;
}
int check_command(char* input_command, char* shell_command)
{
    return strncmp(input_command, shell_command, strlen(shell_command)) == 0;
}

int check_format(char* command)
{
    int n = strlen(command);
    if(command[n-1] == 't' && command[n-2] == 'x' && command[n-3] == 't' && command[n-4] == '.')
        return 1;
    else
        return 0;
}

