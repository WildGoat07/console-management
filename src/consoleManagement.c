#include <stdio.h>
#include <stdlib.h>
#include "consoleManagement.h"
#include <termios.h>
#include <string.h>
#include <stdbool.h>
//https://www.includehelp.com/c-programs/gotoxy-clrscr-getch-getche-for-gcc-linux.aspx
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);                 //grab old terminal i/o settings
    new = old;                          //make new settings same as old settings
    new.c_lflag &= ~ICANON;             //disable buffered i/o
    new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &new);        //apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/*
Read 1 character without echo
getch() function definition.
*/
char getch(void)
{
    return getch_(0);
}

/*
Read 1 character with echo
getche() function definition.
*/
char getche(void)
{
    return getch_(1);
}
color console_color(uint8_t r, uint8_t g, uint8_t b)
{
    color c;
    c.r = r;
    c.g = g;
    c.b = b;
    return c;
}
void console_formatMode(char *content, uint8_t flags)
{
    char str[50] = "";
    bool firstAdded = false;
    if (flags & CONSOLE_FLAG_BOLD)
    {
        strcat(str, "1");
        firstAdded = true;
    }
    if (flags & CONSOLE_FLAG_UNDERLINE)
        if (firstAdded)
            strcat(str, ";4");
        else
        {
            strcat(str, "4");
            firstAdded = true;
        }
    if (flags & CONSOLE_FLAG_BLINK)
        if (firstAdded)
            strcat(str, ";5");
        else
        {
            strcat(str, "5");
            firstAdded = true;
        }
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        if (firstAdded)
            strcat(str, ";7");
        else
            strcat(str, "7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}
void console_formatRGBBackground(char *content, color background)
{
    printf("\x1b[48;2;%d;%d;%dm%s\x1b[0m", background.r, background.g, background.b, content);
}
void console_formatRGBBackgroundMode(char *content, color background, uint8_t flags)
{
    char str[50];
    snprintf(str, 50, "48;2;%d;%d;%d", background.r, background.g, background.b);
    if (flags & CONSOLE_FLAG_BOLD)
        strcat(str, ";1");
    if (flags & CONSOLE_FLAG_UNDERLINE)
        strcat(str, ";4");
    if (flags & CONSOLE_FLAG_BLINK)
        strcat(str, ";5");
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        strcat(str, ";7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}
void console_formatSystemBackground(char *content, int background)
{
    printf("\x1b[%dm%s\x1b[0m", background, content);
}
void console_formatSystemBackgroundMode(char *content, int background, uint8_t flags)
{
    char str[50];
    snprintf(str, 50, "%d", background + 10);
    if (flags & CONSOLE_FLAG_BOLD)
        strcat(str, ";1");
    if (flags & CONSOLE_FLAG_UNDERLINE)
        strcat(str, ";4");
    if (flags & CONSOLE_FLAG_BLINK)
        strcat(str, ";5");
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        strcat(str, ";7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}
void console_formatRGBForeground(char *content, color foreground)
{
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", foreground.r, foreground.g, foreground.b, content);
}
void console_formatRGBForegroundMode(char *content, color foreground, uint8_t flags)
{
    char str[50];
    snprintf(str, 50, "38;2;%d;%d;%d", foreground.r, foreground.g, foreground.b);
    if (flags & CONSOLE_FLAG_BOLD)
        strcat(str, ";1");
    if (flags & CONSOLE_FLAG_UNDERLINE)
        strcat(str, ";4");
    if (flags & CONSOLE_FLAG_BLINK)
        strcat(str, ";5");
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        strcat(str, ";7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}
void console_formatSystemForeground(char *content, int foreground)
{
    printf("\x1b[%dm%s\x1b[0m", foreground, content);
}
void console_formatSystemForegroundMode(char *content, int foreground, uint8_t flags)
{
    char str[50];
    snprintf(str, 50, "%d", foreground);
    if (flags & CONSOLE_FLAG_BOLD)
        strcat(str, ";1");
    if (flags & CONSOLE_FLAG_UNDERLINE)
        strcat(str, ";4");
    if (flags & CONSOLE_FLAG_BLINK)
        strcat(str, ";5");
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        strcat(str, ";7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}

void console_formatRGBColor(char *content, color foreground, color background)
{
    printf("\x1b[38;2;%d;%d;%d;48;2;%d;%d;%dm%s\x1b[0m", foreground.r, foreground.g, foreground.b, background.r, background.g, background.b, content);
}
void console_formatRGBColorMode(char *content, color foreground, color background, uint8_t flags)
{
    char str[50];
    snprintf(str, 50, "38;2;%d;%d;%d;48;2;%d;%d;%d", foreground.r, foreground.g, foreground.b, background.r, background.g, background.b);
    if (flags & CONSOLE_FLAG_BOLD)
        strcat(str, ";1");
    if (flags & CONSOLE_FLAG_UNDERLINE)
        strcat(str, ";4");
    if (flags & CONSOLE_FLAG_BLINK)
        strcat(str, ";5");
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        strcat(str, ";7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}
void console_formatSystemColor(char *content, int foreground, int background)
{
    printf("\x1b[%d;%dm%s\x1b[0m", foreground, background + 10, content);
}
void console_formatSystemColorMode(char *content, int foreground, int background, uint8_t flags)
{
    char str[50];
    snprintf(str, 50, "%d;%d", foreground, background + 10);
    if (flags & CONSOLE_FLAG_BOLD)
        strcat(str, ";1");
    if (flags & CONSOLE_FLAG_UNDERLINE)
        strcat(str, ";4");
    if (flags & CONSOLE_FLAG_BLINK)
        strcat(str, ";5");
    if (flags & CONSOLE_FLAG_REVERSE_COLOR)
        strcat(str, ";7");
    printf("\x1b[%sm%s\x1b[0m", str, content);
}
void console_saveCursorPosition()
{
    printf("\x1b[s");
}
void console_restoreCursorPosition()
{
    printf("\x1b[u");
}
void console_eraseEndOfLine()
{
    printf("\x1b[K");
}
void console_moveCursorPosition(int x, int y)
{
    if (x > 0)
        printf("\x1b[%dC", x);
    else if (x < 0)
        printf("\x1b[%dD", -x);
    if (y > 0)
        printf("\x1b[%dA", y);
    else if (x < 0)
        printf("\x1b[%dB", -y);
}
void console_setCursorPosition(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}
void console_clearScreen()
{
    printf("\x1b[2J");
}

int console_getArrowPressed()
{
    //https://stackoverflow.com/a/10473315
    int var = getch();
    if (var == 27)
    {
        getch();
        switch (getch())
        {
        case 65:
            return CONSOLE_KEY_UP;
        case 66:
            return CONSOLE_KEY_DOWN;
        case 68:
            return CONSOLE_KEY_LEFT;
        case 67:
            return CONSOLE_KEY_RIGHT;
        }
    }
    else if (var == 10)
        return CONSOLE_KEY_RETURN;
    else
        return CONSOLE_KEY_OTHER;
}
