#pragma once

#include "sudoku/SudokuBoard.hpp"

namespace sudoku
{

class SudokuSolver
{
public:
    // Solves the Sudoku board using the backtracking algorithm.
    bool solve(SudokuBoard& board);

private:
    // Finds the next empty cell on the board.
    bool findEmptyCell(const SudokuBoard& board, int& row, int& col);
};

} // namespace sudoku
