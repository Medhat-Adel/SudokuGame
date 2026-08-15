#pragma once

#include "sudoku/SudokuBoard.hpp"
#include "sudoku/SudokuSolver.hpp"
#include "sudoku/SudokuFileManager.hpp"

#include <array>

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

    // Displays the main menu.
    void displayMenu() const;

    // Handles the main menu choices.
    void handleMenuChoice(int choice);

    // Handles player moves.
    void play();

    // Loads a puzzle from a file.
    void loadFromFile();

    // Saves the current puzzle to a file.
    void saveToFile();

    // Checks whether the given coordinates are valid.
    bool isValidPosition(int row, int col) const;

    SudokuBoard board;
    SudokuSolver solver;
    SudokuFileManager fileManager;

    // Stores the original puzzle so given cells cannot be modified.
    std::array<std::array<int, 9>, 9> originalBoard;
};

} // namespace sudoku