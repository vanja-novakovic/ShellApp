#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "string_manipulations.h"
#define MAX_SIZE 200

void create(char* input_command)
{
    char* arguments = malloc(sizeof(char) * MAX_SIZE);
    char* path = malloc(sizeof(char) * MAX_SIZE);

    strcpy(arguments, extract_string(input_command, "create "));
    trim_front_spaces(arguments);
    trim_back_spaces(arguments);

    int result;
    if(arguments[0] == '-' && arguments[1] == 'd') // create a folder
    {
        strcpy(arguments, extract_string(arguments, "-d "));
        trim_front_spaces(arguments);
        if(strstr(arguments, "\\") == NULL) //only name is given so we should make a full path
        {
            _getcwd(path, MAX_SIZE);
            strcat(path, "\\");
            strcat(path, arguments);
            result = mkdir(path);
        }
        else //full path is given
            result = mkdir(arguments);

        if(result == -1)
            printf("An error occured. Check path and/or directory name and try again!\nNote: A directory name can't contain any of the following characters: \\ / : * ? < > |\n");
        if(result == 0)
            printf("Successfully created. \n");
        return;
    }
    else //create file
    {
        FILE *new_file = fopen(arguments, "w");
        if(new_file == NULL)
            printf("An error occured. Check path and/or file name and try again!\nNote: A file name can't contain any of the following characters: \\ / : * ? < > |\n");
        else
        {
            printf("Successfully created. \n");
            fclose(new_file);
        }
    }
    free(path);
    free(arguments);
    return;
}
