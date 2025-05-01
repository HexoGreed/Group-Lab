#include <iostream>
#include <limits>
#include "board.h"

int main() {
    int rows, cols, mines;
    std::cout << "Welcome to Minesweeper!" << std::endl;
    std::cout << "Select difficulty:\n"
        << " 1) Beginner    (9x9, 10 mines)\n"
        << " 2) Intermediate (16x16, 40 mines)\n"
        << " 3) Expert       (16x30, 99 mines)\n"
        << "Choice: ";
    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
    }
    switch (choice) {
    case 2: rows = 16; cols = 16; mines = 40; break;
    case 3: rows = 16; cols = 30; mines = 99; break;
    default: rows = 9; cols = 9; mines = 10; break;
    }

    // Initialize the board
    Board board;
    board.initialize(rows, cols, mines);

    while (!board.lostGame() && !board.wonGame()) {
        board.printBoard();
        char cmd;
        int r;
        int c;
        bool validInput = false;

        while (!validInput) {
            std::cout << "Enter move (r row col  or  f row col), e.g. r 2 3: ";

            // Clear any leftover input before reading new input
            std::cin.clear();

            // Read the command and coordinates
            if (!(std::cin >> cmd >> r >> c)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input format. Try again.\n";
                continue;
            }

            // Flush the rest of the line (in case of extra input)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Validate command
            if (cmd != 'r' && cmd != 'f') {
                std::cout << "Invalid command. Use 'r' to reveal or 'f' to flag.\n";
                continue;
            }

            // Validate row and column
            if (r < 1 || r > rows || c < 1 || c > cols) {
                std::cout << "Position out of bounds. Row must be 1-" << rows
                    << " and column must be 1-" << cols << ".\n";
                continue;
            }

            // Input is valid
            validInput = true;

            // Process the move
            if (cmd == 'r') {
                board.revealCell(r - 1, c - 1);
            }
            else if (cmd == 'f') {
                board.toggleFlag(r - 1, c - 1);
            }
        }
    }
   
    board.printBoard();
    if (board.lostGame()) std::cout << "BOOM! You hit a mine.\n";
    else std::cout << "Congrats! You cleared the field.\n";
    return 0;
}
