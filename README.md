🙋‍♂️ About Me
Hi! I’m Mohit. I built this Sudoku Solver as part of my learning journey into C++ and algorithmic problem-solving. Feel free to fork or suggest improvements!

# Sudoku Solver in C++

This is a terminal-based Sudoku Solver built using C++. It allows users to input a custom 9x9 Sudoku puzzle and solves it using a recursive backtracking algorithm. The project includes input validation, a clean user interface, and board visualization.

---

## Features

* Interactive user input with validation
* Fancy board visualization before and after solving
* Detects if a Sudoku puzzle is unsolvable
* Ensures only 9 digits are entered per row
* Uses classic backtracking with safety checks

---

## How to Run

### Prerequisites

* A C++ compiler (such as g++)
* A terminal or command prompt
* (Optional) Visual Studio Code or another C++-compatible editor

### Compile and Run

```bash
g++ sudoku_solver.cpp -o sudoku_solver
./sudoku_solver
```

---

## Input Format

You will be prompted to enter 9 rows. Each row must contain exactly 9 integers (0–9), separated by spaces. Use `0` to represent an empty cell.

If more or fewer than 9 values are entered, you'll be prompted to re-enter that row.

---

## Output Format

The solver prints:

* The initial Sudoku board in a visual format
* A message indicating whether the puzzle is solvable
* The final board if the puzzle is solvable

---

## Example

```
Enter Sudoku board (9 values per row, 0 for empty):
Enter row 1: 5 3 0 0 7 0 0 0 0
Enter row 2: 6 0 0 1 9 5 0 0 0
...

Sudoku Before Solving:
+-------+-------+-------+
| 5 3 . | . 7 . | . . . |
| 6 . . | 1 9 5 | . . . |
| . 9 8 | . . . | . 6 . |
+-------+-------+-------+
...

Sudoku Solved Successfully!
+-------+-------+-------+
| 5 3 4 | 6 7 8 | 9 1 2 |
| 6 7 2 | 1 9 5 | 3 4 8 |
| 1 9 8 | 3 4 2 | 5 6 7 |
+-------+-------+-------+
...
```

---

## Files

```
SudokuSolver/
│
├── sudoku_solver.cpp     # Source code
├── README.md             # This file
└── .gitignore            # Optional (ignore executables and build files)
```

---


