#include "../include/sudoku.h"
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;

Box ** createBoxes() {
    Box ** boxes;
    int i,j;
   
    boxes = (Box **)malloc(9 * sizeof(Box*)); // 9 boxes
    
    // malloc for each box
    for(i = 0; i < 9; i++){
        boxes[i] = (Box *)malloc(sizeof(Box));
        boxes[i]->squares = (Square **)malloc(9 * sizeof(Square*));
        boxes[i]->numbers = 0;
        boxes[i]->solvable = 0;
        
        // possible array
        for(j = 0; j < 9; j++){
            boxes[i]->possible[j] =0;       
        }
    }
    return boxes;
}

int updateBoxes(Square ***sudoku, int row, int column) {
    int i;
    int number = sudoku[row][column]->number;
    Box * box = sudoku[row][column]->box;
    
    for (i = 0; i < 9; i++){
        if(box->squares[i]->possible[number - 1] == 0){
            box->squares[i]->solvable--;
            box->squares[i]->possible[number - 1] = 1;
            
            return 1;
        }
    }
    return 1;
}   

int boxSingles(Square  *** sudoku, Box ** boxes) {
    int i,j,k;
    int count;
    int temp;
    for ( i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            count = 0;
            // if(boxes[i]->squares[j]->solvable == 1){
            //     number = boxes[i]->squares[j]->number;
            for(k = 0; k < 9; k++){
                if( boxes[i]->squares[k]->number != 0){
                    continue;
                }
                if(boxes[i]->squares[k]->possible[j] == 0){
                count++; 
                temp = k;
                }
                if(count == 2) break;
            }
            if(count == 1){    // its solvable
                    boxes[i]->squares[temp]->number = j + 1;
                    UNSOLVED--;
                    boxes[i]->squares[temp]->solvable = 1;

                    updateSudoku(sudoku, boxes[i]->squares[temp]->row, boxes[i]->squares[temp]->col);

                    return 1; // success
                }
        }
    }
    return 0; // failure
}