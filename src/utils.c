#include <utils/utils.h>

locale char char_to_digit [256] = {
    ['1'] = 1,
    ['2'] = 2,
    ['3'] = 3,
    ['4'] = 4,
    ['5'] = 5,
    ['6'] = 6,
    ['7'] = 7,
    ['8'] = 8,
    ['9'] = 9
};

private int is_player_turn = PLAYER_ONE;

void board_reset (char *board)
{
    is_player_turn = PLAYER_ONE;
    for (size_t i = 0; i < 9; i++)
        board[i] = ' ';
}

void flush_stdin()
{
    char ch = 0;
    while ((ch = getchar()) != EOF && ch != '\n');
}

locale int get_user_input()
{

    char ch = getchar();

    flush_stdin();

    return char_to_digit[ch];
}


/*
    --> Display format <--
\n
\t         |       |
\t    [X]  |  [X]  |  [X]
\t  =======================
\t    [X]  |  [X]  |  [X]
\t  =======================
\t    [X]  |  [X]  |  [X]
\t         |       |
\n
*/

#define colorize(x) (board[x]== 'X') ? T_BOLD C_RED : C_GREEN , board[x], C_RESET

void display_board(char *board) {
    clear_screen();
    putchar('\n');
    printf (T_BOLD "\t       |       |       \n");
    printf (T_BOLD"\t  [" T_BOLD "%s%c%s" T_BOLD "]  |  ["T_BOLD"%s%c%s"T_BOLD"]  |  ["T_BOLD"%s%c%s"T_BOLD"]\n", colorize(0), colorize(1), colorize(2));
    printf ("\t========================\n");
    printf (T_BOLD"\t  [" T_BOLD "%s%c%s" T_BOLD "]  |  ["T_BOLD"%s%c%s"T_BOLD"]  |  ["T_BOLD"%s%c%s"T_BOLD"]\n", colorize(3), colorize(4), colorize(5));
    printf ("\t========================\n");
    printf (T_BOLD"\t  [" T_BOLD "%s%c%s" T_BOLD "]  |  ["T_BOLD"%s%c%s"T_BOLD"]  |  ["T_BOLD"%s%c%s"T_BOLD"]\n", colorize(6), colorize(7), colorize(8));
    printf (T_BOLD "\t       |       |       \n");
    putchar('\n');
}


locale int check_game_state(char *board)
{
	// Horizantal Check for X
	     if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X') return PLAYER_ONE;
	else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') return PLAYER_ONE;
	else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') return PLAYER_ONE;

	// Vertical Check for X
	else if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') return PLAYER_ONE;
	else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return PLAYER_ONE;
	else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') return PLAYER_ONE;

	// A \ Check and a / Check for X
	else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') return PLAYER_ONE;
	else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') return PLAYER_ONE;


	// Horizantal Check for O
    else if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O') return PLAYER_TWO;
	else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') return PLAYER_TWO;
	else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') return PLAYER_TWO;

	// Vertical Check for O
	else if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') return PLAYER_TWO;
	else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') return PLAYER_TWO;
	else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') return PLAYER_TWO;

	// A \ Check and a / Check for O
	else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') return PLAYER_TWO;
	else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O') return PLAYER_TWO;


	// Check for a Tie.
    else if(board[0] != ' ' && board[1] != ' ' && board[2] != ' '
	     && board[3] != ' ' && board[4] != ' ' && board[5] != ' '
	     && board[6] != ' ' && board[7] != ' ' && board[8] != ' ') return PLAYER_DRAW;
    //printf("hello");

    return GAME_CONTINUE;
}

int move(char *board)
{
    printf(T_BOLD "Players %s's turn. (1-9) ", (is_player_turn == PLAYER_ONE)? "one" : "two");
    int move = get_user_input();

    if ( move == 0 ) {
        return INVALID_MOVE;
    } else if ( board[move-1] != ' '){
        return OCCUPIED_MOVE;
    } else {
        board[move-1] = (is_player_turn == PLAYER_ONE)? 'X' : 'O';
        is_player_turn = (is_player_turn == PLAYER_ONE)? PLAYER_TWO : PLAYER_ONE;
    }

    return check_game_state(board);
}
