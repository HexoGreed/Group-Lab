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
	void PLACE_MINE_INDIVIDUALLY(int row, int col);  // helper method
	int countAdjacentMines(int row, int col) const;  // Helper method

};