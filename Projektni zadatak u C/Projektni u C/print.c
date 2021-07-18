#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "string_manipulations.h"
#define MAX_SIZE 200

void print(char* input_command)
{
    if(check_format(input_command) == 1) ///it means its .txt
    {
        char* file_name = malloc(sizeof(char) * MAX_SIZE);
        char str[MAX_SIZE];
        if (file_name != NULL)
        {
            strcpy(file_name, extract_string(input_command, "print "));
            trim_front_spaces(file_name);
        }

        FILE* file = fopen(file_name, "r");
        if(file == NULL)
            printf("No such file!\n");
        else
        {
            printf("\nFile content: \n");
            while((fgets(str, MAX_SIZE, file) != NULL))
                printf("%s", str);
            fclose(file);
        }
        printf("\n\n");
        free(file_name);
    }
    else
        printf("Check help in case you are using command incorrectly.\nNote: Only .txt format is supported.\n");
    return;

}
