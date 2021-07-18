#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directory.h"
void where(char* input_command)
{
    if(!strcmp(input_command, "where"))
        current_directory();
    else
        printf("Invalid command call. Check help.\n");
    return;
}
