#ifndef DEF_CONSOLE_COLORS_H
#define DEF_CONSOLE_COLORS_H
#include <stdint.h>
//https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define CONSOLE_COLOR_BLACK 30
#define CONSOLE_COLOR_RED 31
#define CONSOLE_COLOR_GREEN 32
#define CONSOLE_COLOR_YELLOW 33
#define CONSOLE_COLOR_BLUE 34
#define CONSOLE_COLOR_MAGENTA 35
#define CONSOLE_COLOR_CYAN 36
#define CONSOLE_COLOR_GREY 90
#define CONSOLE_COLOR_GRAY CONSOLE_COLOR_GREY
#define CONSOLE_COLOR_BRIGHT_GREY 37
#define CONSOLE_COLOR_BRIGHT_GRAY CONSOLE_COLOR_BRIGHT_GREY
#define CONSOLE_COLOR_BRIGHT_RED 91
#define CONSOLE_COLOR_BRIGHT_GREEN 92
#define CONSOLE_COLOR_BRIGHT_YELLOW 93
#define CONSOLE_COLOR_BRIGHT_BLUE 94
#define CONSOLE_COLOR_BRIGHT_MAGENTA 95
#define CONSOLE_COLOR_BRIGHT_CYAN 96
#define CONSOLE_COLOR_WHITE 97

#define CONSOLE_FLAG_BOLD 0b1 << 0
#define CONSOLE_FLAG_UNDERLINE 0b1 << 1
#define CONSOLE_FLAG_BLINK 0b1 << 2
#define CONSOLE_FLAG_REVERSE_COLOR 0b1 << 3

/**
 * @brief  color structure
 */
typedef struct
{
    /**
     * @brief  red channel of the color
     */
    uint8_t r;
    /**
     * @brief  green channel of the color
     */
    uint8_t g;
    /**
     * @brief  blue channel of the color
     */
    uint8_t b;
} color;
/**
 * @brief  Creates a color from the given rgb channels
 * @param red red channel value
 * @param green green channel value
 * @param blue blue channel value
 * @return color structure 
 */
color console_color(uint8_t red, uint8_t green, uint8_t blue);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param  flags flags to apply
 * @return void
 */
void console_formatMode(char *content, uint8_t flags);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param background background color of the text
 * @return void
 */
void console_formatRGBBackground(char *content, color background);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param background background color of the text
 * @param  flags flags to apply
 * @return void
 */
void console_formatRGBBackgroundMode(char *content, color background, uint8_t flags);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param background background color of the text
 * @return void
 */
void console_formatSystemBackground(char *content, int background);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param background background color of the text
 * @param  flags flags to apply
 * @return void
 */
void console_formatSystemBackgroundMode(char *content, int background, uint8_t flags);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @return void
 */
void console_formatRGBForeground(char *content, color foreground);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @param  flags flags to apply
 * @return void
 */
void console_formatRGBForegroundMode(char *content, color foreground, uint8_t flags);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @return void
 */
void console_formatSystemForeground(char *content, int foreground);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @param  flags flags to apply
 * @return void
 */
void console_formatSystemForegroundMode(char *, int foreground, uint8_t flags);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @param background background color of the text
 * @return void
 */
void console_formatRGBColor(char *content, color foreground, color background);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @param background background color of the text
 * @param  flags flags to apply
 * @return void
 */
void console_formatRGBColorMode(char *content, color foreground, color background, uint8_t flags);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @param background background color of the text
 * @return void
 */
void console_formatSystemColor(char *content, int foreground, int background);
/**
 * @brief  Writes formatted text in the console
 * @param  content string to write in the console 
 * @param foreground foreground color of the text
 * @param background background color of the text
 * @param  flags flags to apply
 * @return void
 */
void console_formatSystemColorMode(char *content, int foreground, int background, uint8_t flags);
/**
 * @brief  Saves the position of the cursor, to be restored later
 * @return void
 */
void console_saveCursorPosition();
/**
 * @brief  Retores the position of the cursor to where it was saved
 * @return void
 */
void console_restoreCursorPosition();
/**
 * @brief  Clears the remaining characters of the current line, including the current position
 * @return void
 */
void console_eraseEndOfLine();
/**
 * @brief  Moves the cursor by a specified offset
 * @param x horizontal offset
 * @param y vertical offset
 * @return void
 */
void console_moveCursorPosition(int x, int y);
/**
 * @brief  Moves the cursor to the specified position
 * @param x horizontal position
 * @param y vertical position
 * @return void
 */
void console_setCursorPosition(int x, int y);
/**
 * @brief  Returns a hint of the arrow key pressed
 * @return hint of the key
 */
int console_getArrowPressed();
/**
 * @brief  Clears the current screen and set the cursor at the default position
 * @return void
 */
void console_clearScreen();

#define CONSOLE_KEY_OTHER 0
#define CONSOLE_KEY_UP 1
#define CONSOLE_KEY_DOWN 2
#define CONSOLE_KEY_LEFT 3
#define CONSOLE_KEY_RIGHT 4
#define CONSOLE_KEY_RETURN 5

char getch();

char getche();

#endif
