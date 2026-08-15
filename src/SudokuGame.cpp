#include "sudoku/SudokuGame.hpp"
#include "sudoku/InputHandler.hpp"
#include "sudoku/SudokuException.hpp"

#include <iostream>
#include <string>

namespace sudoku
{

void SudokuGame::loadPuzzle()
{
    originalBoard =
    {{
        {{5, 3, 0, 0, 7, 0, 0, 0, 0}},
        {{6, 0, 0, 1, 9, 5, 0, 0, 0}},
        {{0, 9, 8, 0, 0, 0, 0, 6, 0}},

        {{8, 0, 0, 0, 6, 0, 0, 0, 3}},
        {{4, 0, 0, 8, 0, 3, 0, 0, 1}},
        {{7, 0, 0, 0, 2, 0, 0, 0, 6}},

        {{0, 6, 0, 0, 0, 0, 2, 8, 0}},
        {{0, 0, 0, 4, 1, 9, 0, 0, 5}},
        {{0, 0, 0, 0, 8, 0, 0, 7, 9}}
    }};

    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            board.setCell(row, col, originalBoard[row][col]);
        }
    }
}

void SudokuGame::displayBoard() const
{
    board.print();
}

void SudokuGame::displayMenu() const
{
    std::cout << "\n";
    std::cout << "1. Enter a move\n";
    std::cout << "2. Solve automatically\n";
    std::cout << "3. Load puzzle from file\n";
    std::cout << "4. Save current puzzle to file\n";
    std::cout << "5. Exit\n";
}

bool SudokuGame::isValidPosition(int row, int col) const
{
    return row >= 0 && row < 9 &&
           col >= 0 && col < 9;
}

void SudokuGame::play()
{
    while (!board.isComplete())
    {
        int row;
        int col;
        int value;

        try
        {
            row = InputHandler::readInt(
                "\nEnter row (1-9) or 0 to return: "
            );

            // Return to the main menu.
            if (row == 0)
            {
                std::cout << "\nReturning to main menu...\n";
                return;
            }

            col = InputHandler::readInt(
                "Enter column (1-9): "
            );

            value = InputHandler::readInt(
                "Enter value (1-9): "
            );
        }
        catch (const SudokuException& e)
        {
            std::cout << "\nError: " << e.what() << '\n';
            continue;
        }

        // Convert user input from 1-9 to 0-8.
        --row;
        --col;

        // Check whether the position is valid.
        if (!isValidPosition(row, col))
        {
            std::cout << "Invalid position. Try again.\n";
            continue;
        }

        // Check whether the value is between 1 and 9.
        if (value < 1 || value > 9)
        {
            std::cout
                << "Invalid value. Enter a number from 1 to 9.\n";
            continue;
        }

        // Prevent modifying original puzzle cells.
        if (originalBoard[row][col] != 0)
        {
            std::cout
                << "This is an original puzzle cell and cannot be modified.\n";
            continue;
        }

        // Check whether the move follows Sudoku rules.
        if (!board.isValidMove(row, col, value))
        {
            std::cout
                << "Invalid move. The value conflicts with the Sudoku rules.\n";
            continue;
        }

        // Place the player's value on the board.
        board.setCell(row, col, value);

        std::cout << "\nMove accepted!\n\n";
        displayBoard();
    }

    std::cout << "\nCongratulations! You solved the Sudoku!\n";
}

void SudokuGame::loadFromFile()
{
    std::string filename;

    std::cout << "\nEnter filename: ";
    std::cin >> filename;

    if (fileManager.load(filename, board))
    {
        std::cout << "\nPuzzle loaded successfully!\n\n";
        displayBoard();
    }
    else
    {
        std::cout << "\nFailed to load puzzle from file.\n";
    }
}

void SudokuGame::saveToFile()
{
    std::string filename;

    std::cout << "\nEnter filename: ";
    std::cin >> filename;

    if (fileManager.save(filename, board))
    {
        std::cout << "\nPuzzle saved successfully!\n";
    }
    else
    {
        std::cout << "\nFailed to save puzzle to file.\n";
    }
}

void SudokuGame::handleMenuChoice(int choice)
{
    switch (choice)
    {
        case 1:
            play();
            break;

        case 2:
            if (solver.solve(board))
            {
                std::cout << "\nPuzzle solved successfully!\n\n";
                displayBoard();
            }
            else
            {
                std::cout << "\nNo solution exists.\n";
            }
            break;

        case 3:
            loadFromFile();
            break;

        case 4:
            saveToFile();
            break;

        case 5:
            std::cout << "\nGoodbye!\n";
            break;

        default:
            std::cout << "\nInvalid option. Please choose 1-5.\n";
            break;
    }
}

void SudokuGame::run()
{
    loadPuzzle();

    int choice = 0;

    std::cout << "=========================\n";
    std::cout << "       SUDOKU GAME\n";
    std::cout << "=========================\n";

    while (choice != 5)
    {
        std::cout << "\nCurrent Board:\n\n";
        displayBoard();

        displayMenu();

        try
        {
            choice = InputHandler::readInt("\nChoose an option: ");
        }
        catch (const SudokuException& e)
        {
            std::cout << "\nError: " << e.what() << '\n';
            continue;
        }

        handleMenuChoice(choice);
    }
}

} // namespace sudoku