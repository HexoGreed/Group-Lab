#include <iostream>
#include <random>
#include <ctime>
#include <vector>

#include "board.h"

Board::Board() {}

Board::~Board() {
	if (cells != nullptr){
		for (int i = 0; i < rows; i++)
		{
			delete[] cells[i];
		}
	delete[] cells;
	}
}

void Board::initialize(int rows, int cols, int mines) {
	this->rows = rows;
	this->cols = cols;
	this->mines = mines;

	cells = new Cell * [rows];
	for (int i = 0; i < rows; i++) {
		cells[i] = new Cell[cols];
	
		for (int j = 0; j < cols; j++) {
			cells[i][j].row = i;
			cells[i][j].col = j;
			cells[i][j].value = ' ';
			cells[i][j].isMine = false;
			cells[i][j].isRevealed = false;
			cells[i][j].isFlagged = false;
		}
	}
	
}

void Board::printBoard() {
	std::cout << " ";
	for (int col = 0; col < cols; ++col) {
		char colLetter = 'a' + col;
		std::cout << colLetter << " ";
	}
	std::cout << std::endl;
	std::cout << "  ";
	for (int col = 0; col < cols; ++col) {
		std::cout << "- ";
	}
	std::cout << std::endl;

	for (int row = 0; row < rows; ++row) {
		std::cout << row + 1 << "| ";
		for (int col = 0; col < cols; ++col) {
			if (cells[row][col].isRevealed) {
				std::cout << cells[row][col].value << " ";
			}
			else if (cells[row][col].isFlagged) {
				std::cout << "F ";
			}
			else {
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
}