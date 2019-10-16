/* Transpose and Dot product of Matrix using 1D array */

#include<stdio.h>

int* dotproduct(int *Amat, int row0, int col0, int *Bmat, int row1, int col1){
    
    if(col0 != row1 ){
        return NULL;
    }
    int *outmat = malloc(sizeof(int)*row0*col1);
    int temp = 0;
    
    for(int i = 0 ; i < row0; i++){
        for(int j = 0; j < col1; j++){
            for(int k = 0; k < col0; k++ ){
                temp += *(Amat + i*col0 + k) * *(Bmat + j + k*col1);
            }
            *(outmat + i*col1 + j) = temp;
            temp = 0;
        }
    }
    return outmat;
}


int* transpose(int *matrix, int rowSize, int colSize){
    
    int *trans = malloc(sizeof(int) * rowSize * colSize);
    for(int i = 0 ; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            *(trans + j*rowSize + i)  = *(matrix + i*colSize + j);
        }
    }
    return trans;
}

int main(void) {
    
    int rowSize = 3;
    int colSize = 4;
    //int inMat[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int *inMat = malloc(sizeof(int) * rowSize * colSize);
    
    int count = 1;
    
     for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            *(inMat + i*colSize + j) = count++;
            printf("%d ", *(inMat + i*colSize + j));
        }
         printf("\n");
    }
    
    int *transMat;
    
    transMat = transpose(inMat,rowSize,colSize);
    
    printf("Transpose \n");
    for(int i = 0; i < colSize; i++){
        for(int j = 0; j < rowSize; j++){
            printf("%d ", *(transMat + i*rowSize + j));
        }
        printf("\n");
    }
    
    int *product;
    
    product = dotproduct(inMat, rowSize, colSize, transMat, colSize, rowSize);
    
    printf("Dot Product\n ");
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < rowSize; j++){
              printf("%d ", *(product + i*rowSize + j));
        }
        printf("\n");
    }
    
    return 0;
}
