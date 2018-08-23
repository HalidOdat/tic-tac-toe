#ifndef   __UTILS_H__
#define   __UTILS_H__

#include <stdint.h>
#include <stdbool.h>


typedef enum GAME_t {
    PLAYER_ONE = 1,
    PLAYER_TWO,
    PLAYER_DRAW,

    VALID_MOVE,
    INVALID_MOVE,
    OCCUPIED_MOVE,

    GAME_CONTINUE
} GAME;

#define private static
#define locale  static

#define persistent static

#ifdef _WIN32
    #include <conio.h>
    #define clear_screen() clrscr()

    #define ANSI_COLOR_RED     ""
    #define ANSI_COLOR_GREEN   ""
    #define ANSI_COLOR_YELLOW  ""
    #define ANSI_COLOR_BLUE    ""
    #define ANSI_COLOR_MAGENTA ""
    #define ANSI_COLOR_CYAN    ""
    #define ANSI_TEXT_BOLD     ""
    #define ANSI_COLOR_RESET   ""
#else
    #include <stdio.h>
    #define clear_screen() printf("\e[1;1H\e[2J");

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_TEXT_BOLD     "\x1b[1m"
    #define ANSI_COLOR_RESET   "\x1b[0m"
#endif

#define C_RED       ANSI_COLOR_RED
#define C_GREEN     ANSI_COLOR_GREEN
#define C_YELLOW    ANSI_COLOR_YELLOW
#define C_BLUE      ANSI_COLOR_BLUE
#define C_MAGENTA   ANSI_COLOR_MAGENTA
#define C_CYAN      ANSI_COLOR_CYAN
#define T_BOLD      ANSI_TEXT_BOLD
#define C_RESET     ANSI_COLOR_RESET

void flush_stdin();
void board_reset (char *board);
void display_board(char *board);
int move(char *board);

#endif /* __UTILS_H__ */
