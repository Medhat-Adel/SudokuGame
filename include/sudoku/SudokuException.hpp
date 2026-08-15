#pragma once

#include <stdexcept>
#include <string>

namespace sudoku
{

class SudokuException : public std::runtime_error
{
public:
    explicit SudokuException(const std::string& message)
        : std::runtime_error(message)
    {
    }
};

} // namespace sudoku