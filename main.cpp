#include "tic_tac_toe.h"
#include <iostream>

using namespace std;

int main()
{
	int winning_of_length, size_of_board, i, j;

	std::cout << "Welcome to Tic-tac-toe Game." << std::endl << std::endl;

	std::cout << "Please enter the size for your board." << std::endl;
	std::cin >> size_of_board;
	std::cout << std::endl;

	std::cout << "Please enter the number of consecutive needed for winning." << std::endl;
	std::cin >> winning_of_length;
	std::cout << std::endl;
	try
	{
		Tic_tac_toe my_game(winning_of_length, size_of_board);

		while (!my_game.get_finish_game())
		{
			std::cout << "The turn now is for the player with " << my_game.get_turn() << ".\n";
			my_game.print_board();

			std::cout << "Please choose where to place " << my_game.get_turn() << " on the board.\n";
			std::cin >> i >> j;
			my_game.enter_choice(my_game.get_turn(), i, j);

			std::cout << "The board after your turn\n";
			my_game.print_board();

			std::cout << std::endl;
		}

		if (my_game.get_turn() == 'x')
		{
			std::cout << "The player with o is winner!!:)";
		}
		else
		{
			std::cout << "The player with x is winner!!:)";
		}
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << "Error: " << ex.what() << '\n';
		return 1;
	}

	return 0;
}
