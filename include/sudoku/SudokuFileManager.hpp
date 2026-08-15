#pragma once

#include "sudoku/SudokuBoard.hpp"

#include <string>

namespace sudoku
{

class SudokuFileManager
{
public:
    // Loads a Sudoku puzzle from a file.
    bool load(const std::string& filename, SudokuBoard& board) const;

    // Saves the current Sudoku board to a file.
    bool save(const std::string& filename, const SudokuBoard& board) const;
};

} // namespace sudoku