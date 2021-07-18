#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_from_stdin.h"
#include "directory.h"
#include "string_manipulations.h"
#include "color.h"
#define MAX_SIZE 200
#define BLACK 0
#define WHITE 15
int login(char* username, char* password)
{
    FILE* user_data = fopen("user_data.txt", "r");
    char* tmp_username = malloc(sizeof(char) * MAX_SIZE);
    char* tmp_password = malloc(sizeof(char) * MAX_SIZE);

    if (user_data != NULL)
    {
        while (fscanf(user_data, "%s %s", tmp_username, tmp_password) != EOF)
            if (strcmp(tmp_username, username) == 0 && strcmp(tmp_password, password) == 0)
            {
                printf("Successful login!\n\n");
                current_directory();
                fclose(user_data);
                return 0;
            }
        fclose(user_data);
    }
    free(tmp_username);
    free(tmp_password);
    return -1;
}

int repeat_login(int value_login_command, char** username)
{
    char* input_command = malloc(sizeof(char) * MAX_SIZE);
    char* password = malloc(sizeof(char) * MAX_SIZE);

    while (value_login_command == -1)
    {
        printf("You are not logged in! Enter 'login' to log in or 'exit' to exit the App.\n Your command is: ");
        read_from_stdin(input_command);
        trim_front_spaces(input_command);
        trim_back_spaces(input_command);
        if (input_command != NULL)
        {
            if (strcmp(input_command, "exit") == 0)
            {
                return 1; //closing app
            }

            else if (strcmp(input_command, "login") == 0)
            {
                printf("\tUsername: ");
                read_from_stdin(*username);
                printf("\tPassword: ");
                set_color(BLACK);
                read_from_stdin(password);
                set_color(WHITE);
                value_login_command = login(*username, password);
            }
        }
        if (input_command == NULL)
            return -1;
    }

    free(input_command);
    free(password);
    return 0;
}
