#pragma once

struct Cell {
	int row;
	int col;
	char value;
	bool isMine;
	bool isRevealed;
	bool isFlagged;

};

class Board {
public:
	Board();
	~Board();
	void initialize(int rows, int cols, int mines);
	void printBoard();
	void placeMines();
	void CalcMinePLacement();

private:
	int rows;
	int cols;
	int mines;
	Cell** cells;
	void PLACE_MINE_INDIVIDUALLY(int row, int col);  // helper method
	int countAdjacentMines(int row, int col) const;  // Helper method

};