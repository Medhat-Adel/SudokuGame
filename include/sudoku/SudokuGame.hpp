#pragma once

#include "sudoku/SudokuBoard.hpp"
#include "sudoku/SudokuSolver.hpp"

namespace sudoku
{

class SudokuGame
{
public:
    // Starts the Sudoku game.
    void run();

private:
    // Loads the initial Sudoku puzzle.
    void loadPuzzle();

    // Displays the current game state.
    void displayBoard() const;

    // Handles player input and moves.
    void play();

    // Checks whether the given coordinates are valid.
    bool isValidPosition(int row, int col) const;

    SudokuBoard board;
    SudokuSolver solver;
};

} // namespace sudoku
