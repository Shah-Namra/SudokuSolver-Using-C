// getting puzzle into our program
#include "../include/sudoku.h"

int UNSOLVED = 81; // 111111111
int SIZE_ROWS = 9;
int SIZE_COLS = 9;

int main() {
    int **puzzle = createPuzzle();
    int progress ;
    Sudoku *sudoku;

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    while(UNSOLVED > 0){
        progress = checkPuzzle(sudoku->squares, sudoku->boxes); // it will give the infite loop
    
        if(progress == 0){
            printf("Failed to solve the puzzle!\n");
            break;
        }
    }
    
    printf("\n\n");
    printPuzzle(sudoku->squares);

    return 0;
}