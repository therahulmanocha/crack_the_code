/*
Source : Codility :

A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000]

*/


int cmpfnc(const void *a,const void *b){
    
    return ((*(int*)a) - (*(int*)b));
}

int solution(int A[], int N) {
    
    if(N == 1 ){
        if(A[0] != 1){
            return 0;
        }
        else{
            return 1;
        }
    }
    
    qsort(A, N , sizeof(int), cmpfnc);
    
    if(A[0] != 1){
        return 0;
    }
    
    for(int i = 1; i < N; i++){
        if(A[i] - A[i-1] != 1){
            return 0;
        }
    }
    return 1;
}


#define SIZE 5
int main(){
    
    int arr_init[SIZE] = {1,2,3,4,6};
   
    int result  = solution(arr_init, SIZE);
    
    printf("is permute = %d \n", result); 
    
}
