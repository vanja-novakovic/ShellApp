#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_from_stdin.h"
#include "login.h"
#include "color.h"
#include "execute_command.h"
#include "string_manipulations.h"
#include "help.h"
#define INTRO_COLOR 3
#define WHITE 15
#define BLACK 0
#define MAX_SIZE 200
int main()
{
    char* input_command = (char*)malloc(sizeof(char) * MAX_SIZE);
    set_color(INTRO_COLOR);
    printf("Welcome to simple ShellApp!\n");
    set_color(WHITE);
    printf("At this moment, available commands are 'login', 'help' and 'exit'.\n*Note: ShellApp is case sensitive.\n\nPlease start with your commands: ");
    read_from_stdin(input_command);

    if (input_command != NULL)
    {
        trim_front_spaces(input_command);
        trim_back_spaces(input_command);
        while (strcmp(input_command, "login") != 0)
        {
            if (strcmp(input_command, "exit") == 0)
            {
                printf("Thank you for using this App!\n");
                return 0; // Exit the app
            }
            else if(strcmp(input_command, "help") == 0)
            {
                help();
                printf("\nEnter your command: ");
            }
            else
            printf("Sorry, you should log in using command 'login' or exit using 'exit'!\n Try again: ");
            read_from_stdin(input_command);
            trim_front_spaces(input_command);
            trim_back_spaces(input_command);
        }
    }

    char* username = malloc(sizeof(char) * MAX_SIZE);
    char* password = malloc(sizeof(char) * MAX_SIZE);

    printf("\tUsername: ");
    read_from_stdin(username);
    printf("\tPassword: ");
    set_color(BLACK);
    read_from_stdin(password);
    set_color(WHITE);
    int login_result = login(username, password);

    if (login_result == -1) // it means it was not successful
    {
        printf(" Invalid login.\n");
        int repeat_login_result;
        repeat_login_result = repeat_login(login_result, &username); // repeat input until its exit or successful login
        if (repeat_login_result == 1) //user entered exit
        {
            printf("Thank you for using this App!\n");
            return 0;
        }
        else if (repeat_login_result == -1)
            printf(" An error occurred.\n");
        else
            login_result = 0;//user is logged in
    }
    // else it was successful
    while (login_result == 0)
    {
       login_result = execute_command(login_result, username); // Now you can use all other possible commands because you are logged in
    }
    free(input_command);
    free(username);
    free(password);
    return 0;
}
