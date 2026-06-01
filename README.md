# Tic-Tac-Toe

A simple Tic-Tac-Toe game written in C++ with unit tests using Google Test.

## Prerequisites

- [CMake](https://cmake.org/download/) (version 3.14 or higher)
- A C++ compiler supporting C++14 or higher.
- Internet connection (to fetch Google Test automatically via CMake).

## Building the Project

### Generic Build (All Platforms)

1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
2. Generate build files:
   ```bash
   cmake ..
   ```
3. Build the project:
   ```bash
   cmake --build .
   ```

### Windows

#### Using Visual Studio (MSVC)
1. Open "Developer Command Prompt for VS".
2. Navigate to the project root.
3. Run:
   ```powershell
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release
   ```
   The executable will be in `build/Release/tic_tac_toe.exe`.

#### Using MinGW/GCC
1. Open your terminal (e.g., PowerShell or CMD).
2. Run:
   ```powershell
   mkdir build
   cd build
   cmake -G "MinGW Makefiles" ..
   cmake --build .
   ```

### macOS (Clang)

1. Open Terminal.
2. Run:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

### Linux (GCC)

1. Open Terminal.
2. Run:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Running the Game

After building, run the executable:

- **Windows**: `build\tic_tac_toe.exe` (or `build\Release\tic_tac_toe.exe`)
- **macOS/Linux**: `./tic_tac_toe` (inside the build directory)

## Running Tests

To run the unit tests:

1. Navigate to the `build` directory.
2. Run the test executable:
   - **Windows**: `build\tic_tac_toe_tests.exe` (or `build\Release\tic_tac_toe_tests.exe`)
   - **macOS/Linux**: `./tic_tac_toe_tests`
3. Alternatively, use CTest:
   ```bash
   ctest --output-on-failure
   ```

## Controls
The game uses a keyboard-based grid:
- `q` `w` `e`
- `a` `s` `d`
- `z` `x` `c`

Each key corresponds to a position on the 3x3 board.
