#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_manipulations.h"
#include "check.h"
#define MAX_SIZE 200

int get_text(char* input_command, char* text)
{
    int n = strlen(input_command);
    int i = 1; // first comes the quote sign
    int j = n - 1;
    // while(i < n && input_command[i++] != '"');
    // this is unnecessary because it must have quote sign at the beginning
    while(j > -1 && input_command[j] != '"')
        j--;
    if(input_command[0] != '"' || input_command[j] != '"' || j == 0)
    {
         return -1;
    }
    else
    {
         int k;
         for(k =0; i < j; i++, k++)
            text[k] = input_command[i];
         text[k] = '\0';
         return j + 1;
    }
}
char* get_file_name(char* input_command, int beginning)
{
    int i, len = strlen(input_command);
    char *file_name = malloc(MAX_SIZE);
    trim_front_spaces(input_command);
    for(i = 0; beginning <= len; beginning++, i++)
        file_name[i] = input_command[beginning];
    file_name[i] = '\0';
    return file_name;
}

void find(char* command)
{
    int line_num = 0;
    int find_result = 0;
    char *input_command = malloc(sizeof(char) * MAX_SIZE);
    strcpy(input_command, extract_string(command, "find "));
    trim_front_spaces(input_command);
    char *text = malloc(sizeof(char) * MAX_SIZE);
    char *file_name = malloc(sizeof(char) * MAX_SIZE);
    char temp[MAX_SIZE];
    int end = get_text(input_command, text);
    extract_string(input_command, text);
    if(end != -1)
    {
        strcpy(file_name, get_file_name(input_command, end));
        trim_front_spaces(file_name);
        if(check_format(file_name) == 0)
        {
            printf("Only .txt format is supported.\n");
            return;
        }
        else
        {
            FILE* file = fopen(file_name, "r");
            if(file == NULL)
            {
                printf("No such file!\n");
                return;
            }
            while(fgets(temp, MAX_SIZE - 1, file) != NULL && find_result == 0)
            {
                if((strstr(temp, text)) != NULL)
                {
                    printf("A match found on line: %d\n", line_num + 1);
                    find_result++;
                }
                line_num++;
            }
            if(find_result == 0)
                printf("Sorry, could not find a match.\n");
            fclose(file);

        }
    }
    else
        printf("Invalid command call. Check help.\n");
    free(file_name);
    free(input_command);
    free(text);
    return;
}
