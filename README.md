
# Rolodex

A simple C++ implementation of a Rolodex (rotary card file) that allows you to insert, delete, and traverse cards (strings) in both directions. Includes command-line and test utilities for managing and displaying the Rolodex contents.

## Features

- Insert cards before or after the current position
- Delete cards by value
- Traverse forward and backward through the Rolodex
- Prevent duplicate entries (optional)
- Print all cards or just the current card
- Report statistics on operations

## Getting Started

### Clone the Repository

```sh
git clone https://github.com/gammaploid/Rolodex.git
cd Rolodex
```

### Build

If you have `g++`:

```sh
g++ -o rolodex main.cpp Rolodex.cpp
```

Or use CMake if a `CMakeLists.txt` is provided:

```sh
cmake -S . -B build
cmake --build build
```

### Run

```sh
./rolodex
```

You can enter words to insert, or `-word` to delete a card.  
Use Ctrl+D (EOF) to finish input.

#### Example

```
Alice
Bob
-Alice
Charlie
```

### Test

To run the test program:

```sh
g++ -o test_rolodex test_rolodex.cpp Rolodex.cpp
./test_rolodex
```

## Files

- `Rolodex.h` / `Rolodex.cpp` — Rolodex class implementation
- `main.cpp` — Command-line interface
- `test_rolodex.cpp` — Example/test usage

## License

This project is for educational purposes only.  
Starter files were provided by instructors at Flinders University.
Do not redistribute or use for commercial purposes.
