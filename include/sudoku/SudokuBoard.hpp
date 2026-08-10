#pragma once

#include <array>

namespace sudoku
{

class SudokuBoard
{
public:
    
    SudokuBoard();
    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;
    bool isValidMove(int row, int col, int value) const;
    bool isComplete() const;
    void clear();    
    void print() const;

private:
    // Stores the 9x9 Sudoku board.
    // A value of 0 represents an empty cell.
    std::array<std::array<int, 9>, 9> board;
    
    bool isValidRow(int row, int value) const;
    bool isValidColumn(int col, int value) const;
    bool isValidBox(int row, int col, int value) const;
};

} // namespace sudoku
