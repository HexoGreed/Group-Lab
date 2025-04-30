#include <iostream>
#include "board.h"

int main() {
    int rows, cols, mines;

    // Get board dimensions and number of mines from the user
    std::cout << "Welcome to Minesweeper!" << std::endl;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    std::cout << "Enter the number of mines: ";
    std::cin >> mines;

    // Initialize the board
    Board board;
    board.initialize(rows, cols, mines);

    // Print the initial board
    std::cout << "Here is your board:" << std::endl;
    board.printBoard();

    return 0;
}