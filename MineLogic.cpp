/*
 * MineLogic.cpp
 *
 *  Created on: Apr 26, 2025
 *      Author: alecc
 */

#include <iostream>
#include <vector>
#include "MineDetect.h"

MineDetector::MineDetector(const std::vector<std::vector<int>>& inputBoard){

	board = inputBoard;
	Rows = board.size();
	Cols = board.empty() ? 0 : board[0].size();

}

MineDetector::~MineDetector() {}


bool MineDetector::isMine(int x, int y) const{

	if(x < 0 || y < 0 || x >= Rows || y >= Cols){
		return false;
	}

	return board[x][y] == -1;
}


int MineDetector::countAdjacentMines(int x, int y) const{

	int mineCount = 0;

	const int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, { 0, -1}, { 0, 1},{ 1, -1}, { 1, 0}, { 1, 1} };

	for (const auto&dir : directions){

		int newx = x + dir[0];

		int newy = y + dir[1];

		if(newx >= 0 && newy >= 0 && newx < Rows && newy < Cols){
			if(board[newx][newy] == -1){
				++mineCount;
			}
		}

	}

	return mineCount;

}
