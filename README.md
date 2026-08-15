# 🎮 Sudoku Game

<p align="center">
  <strong>A Modern C++ Console-Based Sudoku Game</strong>
</p>

<p align="center">
  A modular and object-oriented Sudoku application featuring manual gameplay,
  automatic solving using recursive backtracking, file persistence,
  input validation, exception handling, and CMake-based project management.
</p>

<p align="center">

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-Build_System-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Git](https://img.shields.io/badge/Git-Version_Control-F05032?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-Repository-181717?style=for-the-badge&logo=github&logoColor=white)
![MinGW](https://img.shields.io/badge/MinGW-GCC-000000?style=for-the-badge)

</p>

---

## 📖 Overview

**Sudoku Game** is a console-based Sudoku application developed in **Modern C++17** with a strong focus on clean architecture, Object-Oriented Programming, algorithmic problem solving, and maintainable project structure.

The application allows users to:

- Play Sudoku interactively.
- Enter and validate moves.
- Prevent modification of original puzzle cells.
- Automatically solve puzzles.
- Save the current board to a file.
- Load puzzles from files.
- Handle invalid user input safely.
- Build the entire project using CMake.

The project was designed as an educational software development project to demonstrate practical applications of **OOP, STL, recursion, algorithms, file handling, exception handling, CMake, and Git**.

---

# ✨ Features

## 🎯 Gameplay

- Interactive console-based Sudoku interface.
- 9×9 Sudoku board representation.
- Manual cell input.
- Real-time move validation.
- Protection of original puzzle cells.
- Automatic detection of completed puzzles.
- Clear and readable board visualization.

## 🧠 Automatic Solver

The game includes an automatic Sudoku solver based on the **recursive Backtracking algorithm**.

The solver:

1. Searches for an empty cell.
2. Attempts values from `1` to `9`.
3. Validates each candidate.
4. Places a valid candidate temporarily.
5. Recursively solves the remaining board.
6. Backtracks when a branch leads to an invalid state.

## 💾 File Management

The application supports:

- Saving the current Sudoku board.
- Loading a Sudoku board from a file.
- Basic file error handling.

## 🛡️ Input Validation

The application handles invalid user input without crashing.

Examples include:

- Non-numeric menu input.
- Invalid row numbers.
- Invalid column numbers.
- Invalid Sudoku values.
- Invalid moves according to Sudoku rules.

## ⚠️ Exception Handling

A custom exception class is used to handle runtime input errors cleanly.

Instead of terminating the application when invalid input is entered, the program reports the error and allows the user to continue.

## 🔧 Build System

The project uses **CMake** for configuration and compilation, making the project easier to build and maintain.

---

# 🏗️ Architecture

The project follows a modular Object-Oriented design where each class has a clear responsibility.

```text
                    ┌──────────────────┐
                    │      main.cpp    │
                    └────────┬─────────┘
                             │
                             ▼
                    ┌──────────────────┐
                    │   SudokuGame     │
                    │                  │
                    │ Game Flow        │
                    │ Menu             │
                    │ User Interaction │
                    └───────┬──────────┘
                            │
              ┌─────────────┼─────────────┐
              │             │             │
              ▼             ▼             ▼
      ┌──────────────┐ ┌──────────────┐ ┌──────────────────┐
      │ SudokuBoard  │ │ SudokuSolver │ │ SudokuFileManager│
      │              │ │              │ │                  │
      │ Board Logic  │ │ Backtracking │ │ Load / Save      │
      │ Validation   │ │ Algorithm    │ │ File I/O         │
      └──────────────┘ └──────────────┘ └──────────────────┘
              │
              ▼
      ┌──────────────────┐
      │   InputHandler   │
      │                  │
      │ Safe Input       │
      │ Validation       │
      └──────────────────┘

              ┌────────────────────┐
              │ SudokuException    │
              │ Custom Exceptions  │
              └────────────────────┘