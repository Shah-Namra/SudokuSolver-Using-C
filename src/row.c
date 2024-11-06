#include "../include/sudoku.h"
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

int checkRows(Square ***sudoku, Box **boxes) {
    int i,j,k;
    int sum[9];
    int place[9];

    printf("Checking Rows!!\n");
    
    // looping through all rows
    for(i=0; i<9; i++) {

        // initialize sum and place
        for(j=0; j<9; j++){
            place[j] = 0;
            sum[j] = 0;
        }

        // each sqaure in row
        for(j=0; j<9; j++) {

            // if the square is not solved
            if(sudoku[i][j]->number != 0) {
                continue;
            }

            // loop through all possible numbers
                for(k=0; k<9; k++) {

                    // if the number {k} is possible
                    if(sudoku[i][j]->possible[k] == 0) { // it is possible
                        sum[k]++;
                        place[k] = j; // store the place of the number
                    }
                }
        }
        for(j=0; j<9; j++){
            if(sum[j] == 1){ // we found the solvable square
            // which one?
            sudoku[i][place[k]] -> number = j+1;
            sudoku[i][place[k]] -> solvable = j+1;
            UNSOLVED--;

            updateSudoku(sudoku, i, place[k]);
            updateBoxes(sudoku, i, place[k]);

            return 1; // success
            }
        } 
    }

    return 0; // failure 
}