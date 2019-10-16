/* 
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Source : https://leetcode.com/problems/set-matrix-zeroes/

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    
    int ncol = *matrixColSize;
    int nrow = matrixSize;/// *matrixColSize;
  
    bool rowhaszero = false;
    bool colhaszero = false;
    for(int c = 0; c < ncol; c++){
        if(matrix[0][c] == 0){
            rowhaszero = true;
            break;
        }
    }
    
    for(int r = 0; r < nrow; r++){
        if(matrix[r][0] == 0){
            colhaszero = true;
            break;
        }
    }
    
    for(int r = 1; r < nrow; r++){
        for(int c = 1; c < ncol; c++){
            if(matrix[r][c] == 0){
                matrix[r][0] = 0;
                matrix[0][c] = 0;
            }
        }
    }
    
    for(int r = 1; r < nrow ; r++){
        if(matrix[r][0]  == 0){
            for(int j = 0; j < ncol ; j++){
                matrix[r][j] = 0;
            }
        }
    }
    
    for(int c = 1; c < ncol ; c++){
        if(matrix[0][c]  == 0){
            for(int j = 0; j < nrow ; j++){
                matrix[j][c] = 0;
            }
        }
    }
    
    if(rowhaszero){
        for(int j = 0; j < ncol ; j++){
                matrix[0][j] = 0;
            }
    }
    
    if(colhaszero){
         for(int j = 0; j < nrow ; j++){
                matrix[j][0] = 0;
            }
    }
    
}

void print_arr(int **matrix, int rowSize, int colSize){
    for(int r = 0; r < rowSize; r++){
        for(int c = 0; c < colSize; c++ ){
            printf("%d  ", matrix[r][c]);
        }
        printf("\n");
    }
    printf(" \n");
}

#define ROWS 3
#define COLS 4
int main(void) {
    printf("set matrix zeros \n");
    
    int image[ROWS][COLS] =
    {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    
    int **matrix = (int **)malloc(sizeof(int *) * ROWS);
    for(int r = 0; r < ROWS; r++){
        *(matrix + r) = malloc(sizeof(int) * COLS);
        for(int c = 0; c < COLS; c++){
            matrix[r][c] = image[r][c];
        }
    }
    
    print_arr(matrix, ROWS, COLS);
    
    int *colSize = malloc(sizeof(int));
    *colSize = COLS; 
    
    setZeroes(matrix, ROWS, colSize);
    
    print_arr(matrix, ROWS, COLS);
}


