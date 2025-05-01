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

	void revealCell(int row, int col);
	void toggleFlag(int row, int col);

	bool lostGame() const;
	bool wonGame() const;
	
	void resetGame();


private:
	int rows;
	int cols;
	int mines;
	bool lost;
	bool won;
	Cell** cells;
};