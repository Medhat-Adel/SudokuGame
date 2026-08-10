#include "sudoku/SudokuBoard.hpp"

#include <iostream>

int main()
{
    sudoku::SudokuBoard board;

    board.setCell(0, 0, 5);
    board.setCell(0, 1, 3);
    board.setCell(1, 0, 6);

    std::cout << "Sudoku Board:\n\n";

    board.print();

    std::cout << "\nCell [0][0]: "
              << board.getCell(0, 0) << '\n';

    std::cout << "\nValid move (0, 2, 5): "
              << std::boolalpha
              << board.isValidMove(0, 2, 5) << '\n';

    std::cout << "Valid move (0, 2, 7): "
              << board.isValidMove(0, 2, 7) << '\n';

    return 0;
}
