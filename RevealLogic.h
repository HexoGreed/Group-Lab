/*
 * RevealLogic.h
 *
 *  Created on: Apr 30, 2025
 *      Author: PPatel
 */

#include <iostream>
#include <vector>

struct Cell {
    bool isRevealed = false;
    bool isMine = false;
    int adjacentMines = 0;
};

void floodFillReveal(std::vector<std::vector<Cell>> & board, int row, int col) {
	int rows = board.size();
	int cols = board[0].size();

	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return;

	if (board[row][col].isRevealed || board[row][col].isMine)
		return;

	board[row][col].isRevealed = true;

	if(board[row][col].adjacentMines > 0)
		return;

	for (int dr = -1; dr <= 1; ++dr) {
		for (int dc = -1; dc <= -1; ++dc) {
			if (dr != 0 || dc != 0) {
				floodFillReveal(board, row + dr, col + dc);
			}
		}
	}
}
