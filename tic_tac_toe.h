#pragma once

#include <iostream>
#include <vector>
#include <string>

class Tic_tac_toe
{
private:
	int winning_length;
	int size_board;
	bool finish_game;
	char turn;
	std::vector<std::vector<char>> board;

public:
	Tic_tac_toe();
	Tic_tac_toe(int w, int s);
	void print_board();
	bool get_finish_game();
	char get_turn();
	void enter_choice(char c, int i, int j);
	void check_win(char c, int i, int j);
};