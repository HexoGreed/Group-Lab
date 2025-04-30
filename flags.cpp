/*
 * flags.cpp
 *
 *  Created on: Apr 29, 2025
 *      Author: Julian Alanis
 */
#include "flags.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

Flags::Flags(Board* board){
	this->board = board;
	this->flagsLeft = board->getMineCount();
}

void Flags::toggleFlag(int row, int col){
	if (row < 0 || row >= board->getRows() || col >= board->getCols()){
		cout << "You can't place a flag there, try again" << endl;
		return;
	}

	Cell& cell = board->getCell(row, col);

	if (cell.isRevealed){
		cout << "You can't place a flag on a revealed cell, try again." << endl;
		return;
	}

	if (cell.isFlagged){
		cell.isFlagged = false;
		flagsLeft++;
		cout << "Flag removed. " << flagsLeft << " flags left." << endl;
	}
	else{
		if (flagsLeft > 0){
			cell.isFlagged = true;
			flagsLeft--;
		}
	}
}

void promptFlag(Flags& flags){
	string input;

	cout << "Where would you like to place/remove a flag? "
			"Enter the cell (ex: a1 or c3)" << endl;
	cin >> input;

	if (input.length() < 2 || !isalpha(input[0]) || !isdigit(input[1])){
		cout << "That's not how you input, try again. " << endl;
		return;
	}

	char colChar = tolower(input[0]);
	int col = colChar - 'a';

	int row;
	try{
		row = stoi(input.substr(1)) - 1;
	}
	catch (...){
		cout << "Invalid row number, try again." << endl;
		return;
	}

	flags.toggleFlag(row, col);
}

int Flags::getFlagsLeft() const{
	return flagsLeft;
}
