# SudokuSolver-Using-C
This project is a simple Sudoku solver algorithm built in C. The idea for this project came from an experience I had on Dusherra when I saw someone solving Sudoku in a long queue. It reminded me of the time I used to solve Sudoku puzzles during my school days while waiting for the school van. During the Diwali holidays, I decided to build a Sudoku solver as a fun project to brush up on my C programming skills.

## Technical Overview:
- This Sudoku solver uses a backtracking algorithm with constraint propagation for efficient solving. The core data structures involved are:

1. **Square**: Represents a cell in the Sudoku grid. It holds information such as the number in the cell, possible values (represented as a 9-bit number), and solvability status.

2. **Box**: Represents a 3x3 sub-grid of the Sudoku. Each box contains 9 squares and holds information regarding solvability and possible numbers for its squares.

3. **Sudoku**: Contains the entire Sudoku puzzle, which is composed of squares and boxes.

## Key functions and techniques include:

- **Constraint Propagation**: When a square is filled, it updates the rows, columns, and boxes to eliminate the possibilities of that number in other squares.
- **Backtracking**: The program iteratively solves each square, checking for solvability by reducing possibilities until a solution is found or the puzzle is determined unsolvable.
- **Optimization**: Techniques like solving single-square boxes and checking rows are used to optimize solving.

Usage Instructions:
1. Compiling the Code:

```
gcc sudoku_solver.c -o sudoku_solver
```
2. Running the Program:
```
./sudoku_solver
```
3. Input Format: The Sudoku grid is represented as a 9x9 array. Empty cells are represented by zeros.


## Acknowledgments

Special thanks to **BadCodingHabits** for the helpful tutorial that guided me through building the solver. Check out their YouTube channel [here](https://www.youtube.com/@badcodinghabits).
