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
	placeMines();
	CalcMinePLacement();
	
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

void Board::placeMines() {
	// Create a list of all possible positions
	std::vector<std::pair<int, int>> positions;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			positions.emplace_back(i, j);
		}
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(positions.begin(), positions.end(), g);

	// Place the mines
	for (int i = 0; i < mines && i < positions.size(); i++) {
		PLACE_MINE_INDIVIDUALLY(positions[i].first, positions[i].second);
	}
}

void Board::PLACE_MINE_INDIVIDUALLY(int row, int col) {
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		cells[row][col].isMine = true;
		cells[row][col].value = '*';
	}
}

int Board::countAdjacentMines(int row, int col) const {
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue; // Skip current cell
			int newRow = row + i;
			int newCol = col + j;
			if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
				if (cells[newRow][newCol].isMine) {
					count++;
				}
			}
		}
	}
	return count;
}




void Board::CalcMinePLacement() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!cells[i][j].isMine) {
				int count = countAdjacentMines(i, j);
				if (count > 0) {
					cells[i][j].value = '0' + count;
				}
				else {
					cells[i][j].value = ' ';
				}
			}
		}
	}
}//this is closing bracket hell
