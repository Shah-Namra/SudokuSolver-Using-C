//creating puzzle and printing the puzzle, showing the puzzle to user
#include "../include/sudoku.h"
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLS;



Sudoku * setUpPuzzle (int ** puzzle){
    Square *** sudoku;
    Box ** boxes;
    int i,j ,k;
    int currentBox = 0;

    sudoku = (Square ***)malloc(9 * sizeof(Square**));
    boxes = createBoxes();  
    // we want to store all the values in sudoku
    for (int i = 0; i < SIZE_ROWS; i++) { // rows

        sudoku[i] = (Square**)malloc(9 * sizeof(Square*));

        for (int j = 0; j < SIZE_COLS; j++) { // cols 

            sudoku[i][j] = (Square*)malloc(sizeof(Square)); // spaec for each square
            
            sudoku[i][j]->number = puzzle[i][j]; // giving the number to the square

            sudoku[i][j]->row = i;
            sudoku[i][j]->col = j;
            sudoku[i][j]->solvable = 9;
            
            // if the number is 0, then it is solvable 
            boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for (int k = 0; k < SIZE_ROWS; k++) { 
                sudoku[i][j]->possible[k] = 0; // initializes to 0
            }

            if(j == 2 )
                currentBox++;
            if(j == 5)
                currentBox++;
        }
        currentBox -= 2;
        if (i == 2 ) 
            currentBox += 3;
        
        if (i == 5) 
            currentBox += 6;
            
        }
    
        for(int i = 0; i < SIZE_ROWS; i++) { // rows
            for (int j = 0; j < SIZE_COLS; j++) { // COLS
                
                // if there is number, that row and col will not have that number
                if (sudoku[i][j]->number != 0) {
                    sudoku[i][j]->solvable = 1;
                    updateSudoku(sudoku, i, j);
                    updateBoxes(sudoku, i, j);
                    UNSOLVED--;
                }
            }
        }
    return createSudoku(sudoku, boxes);
}


int updateSudoku (Square *** sudoku, int row, int col){
    int x;
    int number = sudoku[row][col]->number;

    // is a sqaure has no., 
    for(x =0; x < SIZE_ROWS; x++){
        if(sudoku[x][col]->possible[number - 1 ] == 0){
            sudoku[x][col]->solvable--; // one number which is not possible in the square
        }
        sudoku[x][col]->possible[number - 1] = 1; // if the number is present on the row than 1 in array
    }
    for(x =0; x < SIZE_COLS; x++){
        if(sudoku[row][x]->possible[number - 1 ] == 0){
            sudoku[row][x]->solvable--; // one number which is not possible in the square
        }
        sudoku[row][x]->possible[number - 1] = 1;
    }
    return 1;
}

int checkPuzzle( Square ***sudoku, Box ** boxes){   

    int counter;

    for(int i=0; i < SIZE_ROWS; i++){ // rows
        for(int j = 0; j < SIZE_COLS; j++){ // cols
            if(sudoku[i][j]->solvable == 1){ 
                solveSquare(sudoku[i][j]); // recalling the function to solve the square
                updateSudoku(sudoku , i,j);
                updateBoxes(sudoku, i, j);
                
                return 1; // most of the time we will return 1
            }
        }
    }

    if (boxSingles(sudoku, boxes)) return 1;// checking for the box singles
    // there are chnces that we dont run this function when we are in the loop


    return checkRows(sudoku, boxes); // checking for the rows
}

int **createPuzzle() {
    int **puzzle;
    int array[9][9] = {
        {5, 6, 2,    0, 0, 0,    8, 1, 4},
        {7, 0, 9,    0, 5, 0,    0, 0, 0},
        {0, 0, 0,    7, 0, 4,    0, 9, 0},

        {0, 9, 0,    5, 0, 7,    0, 0, 0},
        {4, 0, 0,    0, 0, 0,    0, 0, 0},
        {0, 0, 0,    2, 0, 1,    9, 5, 8},

        {0, 5, 0,    0, 0, 6,    0, 0, 0},
        {6, 0, 0,    0, 2, 8,    0, 7, 9},
        {0, 0, 0,    1, 0, 0,    8, 6, 0}
    };
    // Dynamically allocate memory for the puzzle
    puzzle = (int **)malloc(9 * sizeof(int *));

    for (int i = 0; i < SIZE_ROWS; i++) {
        puzzle[i] = (int *)malloc(9 * sizeof(int));
        for (int j = 0; j < SIZE_COLS; j++) {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

// displaying the sudoku puzzle
void printPuzzle(Square *** puzzle) {
     int i, j;

    printf("-------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++){
        printf("|");
        for (j = 0; j < SIZE_COLS; j++){  //  cols
            printf(" %d ", puzzle[i][j]->number);

            if (((j + 1) % 3) == 0){
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0){
            printf("-------------------------------\n");
        }
        
    }
}

// int updateBoxes (Box ** boxes, Square * square){
//     int i;
//     for(i = 0; i < 9; i++){
//         if(boxes[i]->squares[0]->row == square->row && boxes[i]->squares[0]->col == square->col){
//             boxes[i]->squares[boxes[i]->numbers] = square;
//             boxes[i]->numbers++;
//             return 1;
//         }
//     }
//     return 0;
// }


Sudoku * createSudoku(Square ***squares, Box ** boxes){
    Sudoku * sudoku;
    sudoku = (Sudoku *)malloc(sizeof(Sudoku));
    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;

}