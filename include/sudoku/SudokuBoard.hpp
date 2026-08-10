#pragma once

#include <array>

namespace sudoku
{

class SudokuBoard
{
public:
    // Constructor: initializes an empty Sudoku board.
    SudokuBoard();

    // Sets a value at the specified row and column.
    void setCell(int row, int col, int value);

    // Returns the value stored at the specified row and column.
    int getCell(int row, int col) const;

    // Checks whether placing a value at the specified position is valid.
    bool isValidMove(int row, int col, int value) const;

    // Checks whether the Sudoku board is completely filled and valid.
    bool isComplete() const;

    // Clears all cells and resets the board to an empty state.
    void clear();

    // Prints the current Sudoku board to the console.
    void print() const;

private:
    // Stores the 9x9 Sudoku board.
    // A value of 0 represents an empty cell.
    std::array<std::array<int, 9>, 9> board;

    // Checks whether the value already exists in the specified row.
    bool isValidRow(int row, int value) const;

    // Checks whether the value already exists in the specified column.
    bool isValidColumn(int col, int value) const;

    // Checks whether the value already exists in the corresponding 3x3 box.
    bool isValidBox(int row, int col, int value) const;
};

} // namespace sudoku
