/*
Source : Codility : https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].

*/

int solution(int A[], int N) {
    
    if(N == 0){
        return 1;
    }
    if(N == 1 ){
        if(A[0]  == 2){
            return 1;
        }
        else{
            return 2;
        }
    }
    
    int *record_table;
    record_table = calloc(N+1 , sizeof(int));
    
    for(int i = 0; i < N; i++){
        record_table[A[i] - 1] = A[i];
        
    }
    
    for(int i = 0; i <= N; i++){
        if(record_table[i] == 0){
            return i+1;
        }
    }
    return 0;
    
}

#define SIZE 4
int main(){
    
    int arr_init[SIZE] = {2,3,1,5};
   
    int result  = solution(arr_init, SIZE);
    
    printf("Missing Elem = %d \n", result); 
    
}
