#include <stdio.h>
#include <stdlib.h>
#include "string_manipulations.h"

void copy(char* input_command)
{
    extract_string(input_command, "copy ");
    trim_front_spaces(input_command);

    int i = 0, n = strlen(input_command);
    char* first_file_name = malloc(sizeof(char) * n);
    char* second_file_name = malloc(sizeof(char) * n);
    int count = 0;
    int k = 0;
    for(j = 0; i = 0; i + 4 < n; i++)
    {
        if(count == 0 && input_command[i] == '.' && input_command[i + 1] == 't' &&
           input_command[i + 2] == 'x' && input_command[i + 3] == 't')
        {
           for(k = 0; k < i + 4; k++)
           first_file_name[k++] = input_command[j++];
           first_file_name[k] = '\0';
           count++;
           extract_string(input_command, first_file_name);
           trim_front_spaces(input_command);
           i = 0;
        }
        if(count == 1 && input_command[i] == '.' && input_command[i + 1] == 't' &&
           input_command[i + 2] == 'x' && input_command[i + 3] == 't')

    }

}
