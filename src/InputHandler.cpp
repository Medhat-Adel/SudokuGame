#include "sudoku/InputHandler.hpp"
#include "sudoku/SudokuException.hpp"

#include <iostream>

namespace sudoku
{

int InputHandler::readInt(const char* prompt)
{
    int value;

    std::cout << prompt;

    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        throw SudokuException("Invalid input. Please enter a number.");
    }

    return value;
}

} // namespace sudoku