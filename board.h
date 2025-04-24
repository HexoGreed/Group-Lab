#pragma once
#include <iostream>

struct Cell {
	int row;
	int col;
	char value;
	bool isMine;
	bool isRevealed;
	bool isFlagged;
};

class Board
{
public: 
	Board();
	~Board();
	void initialize(int rows, int cols, int mines);
	void printBoard();

private:
	int rows;
	int cols;
	int mines;
	Cell** cells;
};