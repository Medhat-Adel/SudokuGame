#include "sudoku/SudokuFileManager.hpp"

#include <fstream>

namespace sudoku
{

bool SudokuFileManager::load(
    const std::string& filename,
    SudokuBoard& board) const
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            int value;

            if (!(file >> value))
            {
                return false;
            }

            board.setCell(row, col, value);
        }
    }

    return true;
}

bool SudokuFileManager::save(
    const std::string& filename,
    const SudokuBoard& board) const
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            file << board.getCell(row, col);

            if (col < 8)
            {
                file << ' ';
            }
        }

        file << '\n';
    }

    return true;
}

} // namespace sudoku