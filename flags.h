/*
 * flags.h
 *
 *  Created on: Apr 29, 2025
 *      Author: Julian Alanis
 */
#pragma once
#include "board.h"

class Flags{
public:
	Flags(Board* board); //passes pointer to board
	void toggleFlag(int row, int col);
	int getFlagsLeft() const;

private:
	Board* board;
	int flagsLeft;
};
void promptFlag(Flags& flags);
