#include "sudoku/SudokuBoard.hpp"
#include <iostream>

namespace sudoku
{

SudokuBoard::SudokuBoard()
{
    clear();
}

void SudokuBoard::clear()
{
    for (auto& row : board)
    {
        row.fill(0);
    }
}

void SudokuBoard::setCell(int row, int col, int value)
{
    board[row][col] = value;
}

int SudokuBoard::getCell(int row, int col) const
{
    return board[row][col];
}

bool SudokuBoard::isValidRow(int row, int value) const
{
    for (int col = 0; col < 9; ++col)
    {
        if (board[row][col] == value)
        {
            return false;
        }
    }

    return true;
}

bool SudokuBoard::isValidColumn(int col, int value) const
{
    for (int row = 0; row < 9; ++row)
    {
        if (board[row][col] == value)
        {
            return false;
        }
    }

    return true;
}

bool SudokuBoard::isValidBox(int row, int col, int value) const
{
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[startRow + i][startCol + j] == value)
            {
                return false;
            }
        }
    }

    return true;
}

bool SudokuBoard::isValidMove(int row, int col, int value) const
{
    // Check if the value is already present in the row.
    if (!isValidRow(row, value))
    {
        return false;
    }

    // Check if the value is already present in the column.
    if (!isValidColumn(col, value))
    {
        return false;
    }

    // Check if the value is already present in the 3x3 box.
    if (!isValidBox(row, col, value))
    {
        return false;
    }

    return true;
}

bool SudokuBoard::isComplete() const
{
    for (const auto& row : board)
    {
        for (int value : row)
        {
            if (value == 0)
            {
                return false;
            }
        }
    }

    return true;
}

void SudokuBoard::print() const
{
    for (int row = 0; row < 9; ++row)
    {
        if (row % 3 == 0 && row != 0)
        {
            std::cout << "------+-------+------\n";
        }

        for (int col = 0; col < 9; ++col)
        {
            if (col % 3 == 0 && col != 0)
            {
                std::cout << "| ";
            }

            if (board[row][col] == 0)
            {
                std::cout << ". ";
            }
            else
            {
                std::cout << board[row][col] << " ";
            }
        }

        std::cout << '\n';
    }
}

} // namespace sudoku