/* 
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
 Source : LeetCode
    Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

*/


void print_arr(int **matrix, int rowSize, int colSize){
    for(int r = 0; r < rowSize; r++){
        for(int c = 0; c < colSize; c++ ){
            printf("%d  ", matrix[r][c]);
        }
        printf("\n");
    }
    printf(" \n");
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = *matrixColSize;
    int nlayers = n / 2;
    
    for(int y = 0; y < nlayers; y++){
        for(int x = y; x < n - 1 - y; x++){
            int temp = matrix[x][n-1-y];
            matrix[x][n-1-y] = matrix[y][x];
            matrix[y][x] = matrix[n-1-x][y];
            matrix[n-1-x][y] = matrix[n-1-y][n-1-x];
            matrix[n-1-y][n-1-x] = temp;
            
        }
    }
}

#define ROWS 3
#define COLS 3
int main(void) {
    printf("rotate image 90\n");
    
    int image[ROWS][COLS] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
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
    
    rotate(matrix, ROWS, colSize);
    
    print_arr(matrix, ROWS, COLS);
}
