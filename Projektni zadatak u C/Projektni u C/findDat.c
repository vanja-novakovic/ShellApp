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
#define LIMIT 1000
int i = 0;
void findDat_tmp_fnc(char* path, char* file_name, int* flag)
{
    struct dirent *de;  // Pointer for directory entry
    char new_path[MAX_SIZE] = {};
    DIR *dr = opendir(path);
    if (dr == NULL)
    {
        *flag = 2;
        //printf("Could not open some directories. You may not have the right of access to personal data.\n" );
        return;
    }
    while ((de = readdir(dr)) != NULL  && i < LIMIT)
        if(strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0)
        {
            i++;
            strcpy(new_path, path);
            strcat(new_path, "\\");
             strcat(new_path, de->d_name);

            if(strcmp(file_name, de->d_name) == 0)
            {
                printf("Existing. Path to it: %s\n", new_path);
                *flag = 1;
                return;
            }

            struct stat path_stat;
            stat(new_path, &path_stat);

            if(S_ISDIR(path_stat.st_mode)) // check if it is folder
            {
                findDat_tmp_fnc(new_path, file_name, flag);
            }
        }

    closedir(dr);
    return;
}
char* get_file_name_for_findDat(char* text)
{
    int i;
    char* new_text = malloc(sizeof(char) * MAX_SIZE);
    for(i = 0; text[i] != ' '; i++)
        new_text[i] = text[i];
    new_text[i] = '\0';
    return new_text;
}
void findDat(char *input_command)
{
    char* text = malloc(sizeof(char) * MAX_SIZE);
    char* file_name = malloc(sizeof(char) * MAX_SIZE);
    char* path = malloc(sizeof(char) * MAX_SIZE);

    strcpy(text, extract_string(input_command, "findDat"));
    trim_front_spaces(text);
    strcpy(file_name, get_file_name_for_findDat(text));
    strcpy(path, extract_string(text, file_name));
    trim_front_spaces(path);
    int flag = 0;
    findDat_tmp_fnc(path, file_name, &flag);
    if(i == LIMIT)
    {
    printf("Sorry, the upper limit (more than %d of files and folders in tree) has been reached.\n", LIMIT);
    flag = 1;
    }
    if(flag == 0)
        printf("Not existing.\n");
    if(flag == 2)
         printf("Invalid command call.\n");
    i = 0;
    free(path);
    free(file_name);
    free(text);
    return;
}
