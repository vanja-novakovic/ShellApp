#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 200
void help()
{
    FILE* file = fopen("help.txt", "r");
    if(file == NULL)
            printf("Sorry, an error occured. Try again!\n");
    else
        {
            char str[MAX_SIZE];
            while((fgets(str, MAX_SIZE, file) != NULL))
                printf("%s", str);
            fclose(file);
        }
    return;
}
