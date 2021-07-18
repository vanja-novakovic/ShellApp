#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <windows.h>
#include "string_manipulations.h"
#define MAX_SIZE 200
int level = 0;
void print_level(int n)
{
    for (int i = 1; i <= 2 * n; i++)
        printf("  ");
}
void list_it(char* path)
{
    struct dirent *de;  // Pointer for directory entry
    char new_path[MAX_SIZE] = {};

    DIR *dr = opendir(path);
    if (dr == NULL)
    {
        printf("Could not open directory.\n" );
        return;
    }

    while ((de = readdir(dr)) != NULL)
        if(strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0)
        {
            strcpy(new_path, path);
            strcat(new_path, "\\");
            strcat(new_path, de->d_name);

            print_level(level);
            printf("%s\n", de->d_name);

            struct stat path_stat;
            stat(new_path, &path_stat);

            if(S_ISDIR(path_stat.st_mode)) // check if it is folder
            {
                level++;
                list_it(new_path);
            }
        }

    closedir(dr);
    level--;
    return;
}
void list(char* input_command)
{
    char* path = malloc(sizeof(char) * MAX_SIZE);
    if(strcmp(input_command, "list") == 0) //list current directory
    {
        _getcwd(path, MAX_SIZE);
        list_it(path);
    }
    else
    {
        strcpy(path, extract_string(input_command, "list"));
        trim_front_spaces(path);
        trim_back_spaces(path);
        list_it(path);
    }
    level = 0;
    return;
}
