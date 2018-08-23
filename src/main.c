#include <utils/utils.h>

char board[] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};


int main (int argc, char *argv[])
{

    int game_state = GAME_CONTINUE;
    bool is_game_over = false;

Start:
    do {
        display_board(board);

        switch (game_state)
        {
            case PLAYER_ONE:
                display_board(board);
                printf(T_BOLD "Player "C_RED"one"C_RESET T_BOLD" has won.\n");
                is_game_over = true;
                break;
            case PLAYER_TWO:
                display_board(board);
                printf(T_BOLD "Player "C_GREEN"two"C_RESET T_BOLD" has won.\n");
                is_game_over = true;
                break;
            case PLAYER_DRAW:
                display_board(board);
                printf(T_BOLD  "It is a draw.\n");
                is_game_over = true;
                break;
            case VALID_MOVE:
                continue;
                break;
            case INVALID_MOVE:
                continue;
                break;
            case OCCUPIED_MOVE:
                continue;
                break;
        }


        if (is_game_over) {
            printf("Do you wish to play again? (y\\n) ");
            if (getchar() == 'n') {
                break;
            } else {
                flush_stdin();
                board_reset(board);
                is_game_over = false;
                game_state   = GAME_CONTINUE;
                goto Start;
            }
        }

    } while ((game_state = move(board)));

    clear_screen();
    return 0;
}
