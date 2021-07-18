#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_from_stdin.h"
#include "color.h"
#include "string_manipulations.h"
#include "where.h"
#include "go.h"
#include "create.h"
#include "print.h"
#include "find.h"
#include "findDat.h"
#include "list.h"
#include "help.h"
#include "check.h"
#include "clear_console.h"
#include "login.h"
#define MAX_SIZE 200

int execute_command(int is_logged_in, char* username)
{
    char* input_command = malloc(sizeof(char) * MAX_SIZE);
    while (is_logged_in == 0)  // User is logged in and all of the commands are available
    {
        color(username);
        if (input_command != NULL && read_from_stdin(input_command) != NULL)
        {
            trim_front_spaces(input_command);
            trim_back_spaces(input_command);
            // WHERE
            if (check_command(input_command, "where"))
                where(input_command);
            // GO
            else if (check_command(input_command, "go"))
                go(input_command);
            //CREATE
            else if (check_command(input_command, "create"))
                create(input_command); //two possibilities
            // LIST
            else if (check_command(input_command, "list"))
                list(input_command);
            //PRINT
            else if (check_command(input_command, "print"))
                print(input_command);
            //FIND
            else if (check_command(input_command, "find "))
                find(input_command);
            //FINDDAT
            else if (check_command(input_command, "findDat"))
                findDat(input_command);
            //CLEAR
            else if (check_command(input_command, "clear"))
                clear_console(input_command);
            //HELP
            else if (check_command(input_command, "help"))
                help();
            //LOGOUT
            else if (!strcmp(input_command, "logout"))
                is_logged_in = -1;
            //EXIT
            else if (check_command(input_command, "exit"))
            {
               printf("Thank you for using this app.\n");
               return 1;
            }
            else if (check_command(input_command, "login"))
                printf("You are already logged in.\n");
            else
                printf("Invalid command.\n");
        }

        while(is_logged_in == -1)
        {
            int value = repeat_login(is_logged_in, &username);
            if(value == 1) //user chose exit
               return 1;
            else if(value == 0)
                is_logged_in = 0;
            else
            {
                printf("An error occurred!\n");
                return -1;
            }
        }
    }
    free(input_command);
    return 1;
}
