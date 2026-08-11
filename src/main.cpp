#include "sudoku/SudokuBoard.hpp"
#include "sudoku/SudokuSolver.hpp"

#include <iostream>

int main()
{
    sudoku::SudokuBoard board;
    sudoku::SudokuSolver solver;

    // Define a valid Sudoku puzzle.
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

    // Load the puzzle into the board.
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            board.setCell(row, col, puzzle[row][col]);
        }
    }

    std::cout << "Original Puzzle:\n\n";
    board.print();

    std::cout << "\nSolving...\n\n";

    if (solver.solve(board))
    {
        std::cout << "Solved Puzzle:\n\n";
        board.print();
    }
    else
    {
        std::cout << "No solution exists.\n";
    }

    return 0;
}
