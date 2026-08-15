# Sudoku Game

A console-based Sudoku Game developed in C++ using Object-Oriented Programming, STL, CMake, and Git.

The project allows the user to play Sudoku manually, solve puzzles automatically using a backtracking algorithm, and save/load puzzles using text files.

---

## Features

- Display a 9x9 Sudoku board.
- Enter Sudoku moves manually.
- Validate moves according to Sudoku rules.
- Prevent modification of original puzzle cells.
- Automatically solve the puzzle using a backtracking algorithm.
- Load Sudoku puzzles from files.
- Save the current puzzle to a file.
- Input validation and exception handling.
- Clean object-oriented project structure.
- Cross-platform build configuration using CMake.

---

## Technologies Used

- **C++17**
- **Object-Oriented Programming (OOP)**
- **STL**
- **Backtracking Algorithm**
- **File I/O**
- **Exception Handling**
- **CMake**
- **Git & GitHub**
- **MinGW / GCC**

---

## Project Structure

```text
SudokuGame/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── include/
│   └── sudoku/
│       ├── SudokuBoard.hpp
│       ├── SudokuSolver.hpp
│       ├── SudokuGame.hpp
│       ├── SudokuFileManager.hpp
│       ├── SudokuException.hpp
│       └── InputHandler.hpp
│
├── src/
│   ├── main.cpp
│   ├── SudokuBoard.cpp
│   ├── SudokuSolver.cpp
│   ├── SudokuGame.cpp
│   ├── SudokuFileManager.cpp
│   └── InputHandler.cpp
│
├── resources/
│   ├── sudoku.ico
│   └── resources.rc
│
└── build/