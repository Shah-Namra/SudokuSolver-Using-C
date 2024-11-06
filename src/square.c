#include "../include/sudoku.h"
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

int solveSquare(Square *square){
     
    for(int i = 0; i< SIZE_ROWS; i++){

        if(square->possible[i] == 0){
            square->number = i + 1;
            square->solvable = 0;
            UNSOLVED--;
        }
    }
}