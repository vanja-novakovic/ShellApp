#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clear_console(char* input_command)
{
    if(!strcmp(input_command, "clear"))
        system("cls");
    else
        printf("Invalid command call. Check help.\n");
    return;
}
