/*
 * MineDetectDriver.cpp
 *
 *  Created on: Apr 29, 2025
 *      Author: alecc
 */


#include <iostream>
#include <vector>
#include "MineDetect.h"
using namespace std;

int main() {

    // -1 = mine, 0 = empty
    vector<vector<int>> board = {
        { 0,  0, -1 }, // Row 1
        { 0, -1,  0 }, // Row 2
        { 0,  0,  0 } // Row 3
    };



    MineDetector detector(board);
    int maxRow = board.size();
    int maxCol = board[0].size();

    	// Pick a cell
    	int  x ; //Row
    	int  y ; //Col


    	while(true){
    		cout << "Pick any cell and check if it's a mine or not: " << endl;
    		cin >> x >> y;

    		if(x >= 1 && x <= maxRow && y >= 1 && y <= maxCol){

    			x -= 1;
    			y -= 1;
    			break;
    		}
    		else{
    			cout << "How did you go out of bounds in Minesweeper? Bro you can literally see the board. Enter a row between 1 and " << maxRow << " and a column between 1 and " << maxCol << "." << endl;
    		}
    	}


    	if(detector.isMine(x, y)){
    		cout << "Minesweeper might not be for you lil bro. Go play Roblox dawg </3. You hit the mine at (" << x + 1 << ", " << y + 1 << ")" << endl;

    	}

    	else{
    		// Counts adjacent mines
    		int minesAround = detector.countAdjacentMines(x, y);
    		cout << "Mines around cell  (" << x + 1 << ", " << y + 1 << "): " << minesAround << endl;
    	}



    return 0;
}

