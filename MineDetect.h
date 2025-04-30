/*
 * MineDetect.h
 *
 *  Created on: Apr 29, 2025
 *      Author: alecc
 */

#ifndef MINEDETECT_H_
#define MINEDETECT_H_

#include <vector>


class MineDetector{

	public:

	 	MineDetector(const std::vector<std::vector<int>>& inputBoard);

		~MineDetector();

		bool isMine(int x, int y) const;

		int countAdjacentMines(int x, int y) const;


	private:

		std::vector<std::vector<int>> board;

		int Rows;

		int Cols;

};




#endif /* MINEDETECT_H_ */
