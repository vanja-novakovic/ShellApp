#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SIZE 200
#define COLOR 13
#define WHITE 15
void set_color(int forg_c)
{
     WORD w_color;
                          //We will need this handle to get the current background attribute
     HANDLE h_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(h_std_out, &csbi))
     {
                     //Mask out all but the background attribute, and add in the foreground color
          w_color = (csbi.wAttributes & 0xF0) + (forg_c & 0x0F);
          SetConsoleTextAttribute(h_std_out, w_color);
     }
     return;
}
void color(char* username)
{
    set_color(COLOR);
    printf("<%s> ", username);
    set_color(WHITE);
    return;
}
