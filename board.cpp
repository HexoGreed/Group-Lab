#include <iostream>
#include <random>
#include <ctime>
#include <vector>
<<<<<<< Updated upstream

=======
#include <algorithm>
>>>>>>> Stashed changes
#include "board.h"

Board::Board()
:
	rows (0),
	cols (0),
	mines (0), 
	lost (false),
	won (false),
	cells (nullptr)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}

Board::~Board() {
	if (cells != nullptr){
		for (int r = 0; r < rows; r++)
		{
			delete[] cells[r];
		}
	delete[] cells;
	}
}

void Board::initialize(int r, int c, int m) {
    rows = r; 
	cols = c; 
	mines = m;
    lost = won = false;

<<<<<<< Updated upstream
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
	std::cout << "  ";
	for (int col = 0; col < cols; ++col) {
		std::cout << col << " ";
	}

	std::cout << std::endl;

	for (int row = 0; row < rows; ++row) {
		std::cout << row << "| ";
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
=======
    cells = new Cell*[rows];
    for (int i = 0; i < rows; ++i) {
        cells[i] = new Cell[cols];
        for (int j = 0; j < cols; ++j) {
            cells[i][j] = { i, j, ' ', false, false, false };
        }
    }

    placeMines();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!cells[i][j].isMine) {
                int cnt = countAdjacentMines(i, j);
                cells[i][j].value = (cnt > 0 ? char('0' + cnt) : ' ');
            }
        }
    }
}

void Board::printBoard() {
    // Print column header
    std::cout << "    ";
    for (int col = 0; col < cols; ++col) {
        if (col < 9)
            std::cout << "\033[1;36m" << (col + 1) << "\033[0m  "; // Two spaces for single-digit columns
        else
            std::cout << "\033[1;36m" << (col + 1) << "\033[0m "; // One space for double-digit columns
    }
    std::cout << std::endl;

    // Calculate total width needed for the separator line
    int totalWidth = 0;
    for (int col = 0; col < cols; ++col) {
        if (col < 9)
            totalWidth += 3; // 3 chars for single-digit (e.g., "1  ")
        else
            totalWidth += 3; // 3 chars for double-digit (e.g., "10 ")
    }

    // Print separator line with exact width
    std::cout << "   +";
    for (int i = 0; i < totalWidth; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (int row = 0; row < rows; ++row) {
        // Print row numbers with color
        std::cout << " \033[1;36m" << row + 1 << "\033[0m";
        if (row + 1 < 10) std::cout << " ";
        std::cout << "| ";

        for (int col = 0; col < cols; ++col) {
            // Print the cell content
            if (cells[row][col].isRevealed) {
                if (cells[row][col].value == ' ')
                    std::cout << " ";
                else if (cells[row][col].value == '*')
                    std::cout << "\033[1;31m*\033[0m";
                else {
                    int num = cells[row][col].value - '0';
                    switch (num) {
                    case 1: std::cout << "\033[1;34m"; break; // Blue
                    case 2: std::cout << "\033[1;32m"; break; // Green
                    case 3: std::cout << "\033[1;31m"; break; // Red
                    case 4: std::cout << "\033[1;35m"; break; // Purple
                    default: std::cout << "\033[1;33m"; break; // Yellow
                    }
                    std::cout << cells[row][col].value << "\033[0m";
                }
            }
            else if (cells[row][col].isFlagged) {
                std::cout << "\033[1;31mF\033[0m";
            }
            else {
                std::cout << "\033[1;30m#\033[0m";
            }

            // Add CONSISTENT spacing between cells
            if (col < cols - 1) {
                if (col < 9)
                    std::cout << "  "; // Two spaces for all cells in columns 1-9
                else
                    std::cout << "  "; // Also two spaces for columns 10+ (consistent)
            }
        }
        std::cout << "|" << std::endl;
    }
    
    // Bottom border with exact width
    std::cout << "   +";
    for (int i = 0; i < totalWidth; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}

void Board::placeMines() {
    std::vector<std::pair<int,int>> positions;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            positions.emplace_back(i, j);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(positions.begin(), positions.end(), g);

    // only one loop now, using size_t to avoid signed/unsigned compare
    size_t limit = std::min<size_t>(positions.size(), static_cast<size_t>(mines));
    for (size_t i = 0; i < limit; ++i) {
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
                cells[i][j].value = (count > 0) ? ('0' + count) : ' ';
            }
        }
    }
}

void Board::revealCell(int row, int col) {
    // Bounds checking
    if (row < 0 || col < 0 || row >= rows || col >= cols) return;

    Cell& c = cells[row][col];

    // Skip if already revealed or flagged
    if (c.isRevealed || c.isFlagged) return;

    // Reveal this cell
    c.isRevealed = true;

    // Check if it's a mine
    if (c.isMine) {
        lost = true;
        return;
    }

    // If this is an empty cell, reveal its neighbors
    if (c.value == ' ') {
        // Check all 8 surrounding cells
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                // Skip the current cell
                if (dr == 0 && dc == 0) continue;

                // Reveal the neighbor
                revealCell(row + dr, col + dc);
            }
        }
    }
}

void Board::toggleFlag(int row, int col) {
	if (row < 0 || col < 0 || row >= rows || col >= cols) return;
	Cell& c = cells[row][col];
	if (!c.isRevealed) c.isFlagged = !c.isFlagged;
}

bool Board::lostGame() const {
	return lost;
}

bool Board::wonGame() const {
	for (int r = 0; r < rows; r++)
     for (int c = 0; c < cols; c++)
	   if (!cells[r][c].isMine && !cells[r][c].isRevealed)
	     return false;
   return true;
}

void Board::resetGame() {
	if (cells != nullptr) {
		for (int r = 0; r < rows; r++) {
			delete[] cells[r];
		}
		delete[] cells;
	}
	cells = nullptr;
	lost = false;
	won = false;
}	
>>>>>>> Stashed changes
