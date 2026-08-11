#include "sudoku/SudokuGame.hpp"

#include <iostream>

namespace sudoku
{

void SudokuGame::loadPuzzle()
{
    int puzzle[9][9] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            board.setCell(row, col, puzzle[row][col]);
        }
    }
}

void SudokuGame::displayBoard() const
{
    board.print();
}

bool SudokuGame::isValidPosition(int row, int col) const
{
    return row >= 0 && row < 9 &&
           col >= 0 && col < 9;
}

void SudokuGame::play()
{
    while (!board.isComplete())
    {
        int row;
        int col;
        int value;

        std::cout << "\nEnter row (1-9): ";
        std::cin >> row;

        std::cout << "Enter column (1-9): ";
        std::cin >> col;

        std::cout << "Enter value (1-9): ";
        std::cin >> value;

        // Convert user input from 1-9 to 0-8.
        --row;
        --col;

        if (!isValidPosition(row, col))
        {
            std::cout << "Invalid position. Try again.\n";
            continue;
        }

        if (value < 1 || value > 9)
        {
            std::cout << "Invalid value. Enter a number from 1 to 9.\n";
            continue;
        }

        if (board.getCell(row, col) != 0)
        {
            std::cout << "This cell is already occupied.\n";
            continue;
        }

        if (!board.isValidMove(row, col, value))
        {
            std::cout << "Invalid move. The value conflicts with the Sudoku rules.\n";
            continue;
        }

        board.setCell(row, col, value);

        std::cout << "\nMove accepted!\n\n";
        displayBoard();
    }

    std::cout << "\nCongratulations! You solved the Sudoku!\n";
}

void SudokuGame::run()
{
    loadPuzzle();

    std::cout << "=====================\n";
    std::cout << "     Sudoku Game\n";
    std::cout << "=====================\n\n";

    displayBoard();

    play();
}

} // namespace sudoku
