#ifndef  SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

// global
extern int UNSOLVED; // 111111111
extern int SIZE; // 9
extern int SIZE_ROWS;
extern int SIZE_COLS;

typedef struct Sudoku{ // contains entire game info
    struct Square *** squares;
    struct Box ** boxes;

}Sudoku;

typedef struct Box{
    struct Square ** squares;
    int numbers;
    int possible[9]; // 9 bit no.
    int solvable; // 9 bit no.
    struct Box * next;
}Box;

typedef struct Square{
    int number; 
    int possible[9]; // 9 bit no. 
    // [1] [1] [1] [1] [1] [1] [1] [1] [1]
    // [9] [8] [7] [6] [5] [4] [3] [2] [1] 
    // 0 means possible and 1 means not possible 

    int solvable; // when 1 no, is left in the square we know which is the no.
    Box *box;
    int row;
    int col;
} Square;



int **createPuzzle(); // returning array
void printPuzzle(Square ***puzzle); // printing the puzzle

Sudoku * setUpPuzzle(int ** puzzle);

Sudoku * createSudoku(Square ***puzzle, Box ** boxes);

int updateSudoku(Square *** sudoku, int row, int column);
int checkPuzzle(Square *** sudoku, Box ** boxes);

int solveSquare(Square * square);

// Box 
Box ** createBoxes();
int updateBoxes(Square *** sudoku ,int row, int column);

int boxSingles(Square ***sudoku, Box **boxes);
int checkRows(Square ***sudoku, Box **boxes);


#endif // no contradiction with #ifndef SUDOKU_H