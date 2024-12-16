#include "tic_tac_toe.h"

Tic_tac_toe::Tic_tac_toe() : winning_length(0),
size_board(0), finish_game(false), turn('x') {}

Tic_tac_toe::Tic_tac_toe(int w, int s)
{
	if (w > s)
	{
		throw w;
	}
	else
	{
		winning_length = w;
		size_board = s;
		finish_game = false;
		turn = 'x';

		for (size_t i = 0; i < size_board; i++)
		{
			std::vector<char> row;

			for (size_t j = 0; j < size_board; j++)
			{
				row.push_back('-');
			}

			board.push_back(row);
		}
	}
}

bool Tic_tac_toe::get_finish_game()
{
	return finish_game;
}

char Tic_tac_toe::get_turn()
{
	return turn;
}

void Tic_tac_toe::print_board()
{
	for (size_t i = 0; i < size_board; i++)
	{
		for (size_t j = 0; j < size_board; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Tic_tac_toe::enter_choice(char c, int i, int j)
{
	if (board[i][j] != '-')
	{
		throw "You enter incorrect place in the board.\n";
	}

	board[i][j] = c;

	if (c == 'x')
	{
		turn = 'o';
	}
	else
	{
		turn = 'x';
	}

	check_win(c, i, j);
}

void Tic_tac_toe::check_win(char c, int i, int j)
{
	int score_row = 0;
	int score_column = 0;
	int score_line = 0;

	for (size_t index = 0; index < size_board; index++)
	{
		//Check if win in the row
		if (board[i][index] == c)
		{
			score_row++;

			if (score_row >= winning_length)
			{
				finish_game = true;
				return;
			}
		}
		else
		{
			score_row = 0;
		}

		//Check if win in the column
		if (board[index][j] == c)
		{
			score_column++;

			if (score_column >= winning_length)
			{
				finish_game = true;
				return;
			}
		}
		else
		{
			score_column = 0;
		}

		//Check if win in the line
		if (i == j)
		{
			if (board[index][index] == c)
			{
				score_line++;

				if (score_line >= winning_length)
				{
					finish_game = true;
					return;
				}
			}
			else
			{
				score_line = 0;
			}
		}
	}
}