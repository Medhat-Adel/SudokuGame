cmake_minimum_required(VERSION 3.20)

project(SudokuGame
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SudokuGame   
    src/main.cpp
    src/SudokuBoard.cpp
    src/SudokuSolver.cpp
    src/SudokuGame.cpp
    src/SudokuFileManager.cpp
    src/InputHandler.cpp
    resources/resources.rc
)

target_include_directories(SudokuGame
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
