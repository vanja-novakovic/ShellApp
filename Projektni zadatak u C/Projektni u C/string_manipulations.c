#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 200

void trim_front_spaces(char* string)
{
    int i = 0, j = 0;
    while (string[i] == ' ' || string[i] == '\t')
        i++;
    while (string[i] != '\0')
        string[j++] = string[i++];
    string[j] = '\0';
    return;
}
void trim_back_spaces(char* string)
{
    strrev(string);
    trim_front_spaces(string);
    strrev(string);
    return;
}
char* extract_string(char* longer_string, char* shorter_string)
{
    int n = strlen(longer_string), m = strlen(shorter_string);
    int i, k = m;
    char new_string[MAX_SIZE] = { 0 };
    for (i = 0; i < n - m; i++)
        new_string[i] = longer_string[k++];
    new_string[i] = '\0';
    return new_string;
};
