#include <iostream>

#include "board.h"

using namespace std;

int main()
{
	Board myBoard;

	myBoard.initialize(10,10,15);

	cout << "MINESWEEPER" << endl;
	myBoard.printBoard();

    return 0;
}