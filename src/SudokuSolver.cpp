#include "sudoku/SudokuSolver.hpp"

namespace sudoku
{

bool SudokuSolver::findEmptyCell(
    const SudokuBoard& board,
    int& row,
    int& col)
{
    for (row = 0; row < 9; ++row)
    {
        for (col = 0; col < 9; ++col)
        {
            if (board.getCell(row, col) == 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool SudokuSolver::solve(SudokuBoard& board)
{
    int row;
    int col;

    // Find the next empty cell.
    if (!findEmptyCell(board, row, col))
    {
        return true;
    }

    // Try every possible value from 1 to 9.
    for (int value = 1; value <= 9; ++value)
    {
        // Check whether the value can be placed in this cell.
        if (board.isValidMove(row, col, value))
        {
            // Place the value temporarily.
            board.setCell(row, col, value);

            // Recursively solve the rest of the board.
            if (solve(board))
            {
                return true;
            }

            // Backtrack if this value leads to a dead end.
            board.setCell(row, col, 0);
        }
    }

    // No valid value was found for this cell.
    return false;
}

} // namespace sudoku

