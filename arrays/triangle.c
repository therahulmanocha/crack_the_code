/*
Source : Codility

An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
Triplet (0, 2, 4) is triangular.

Write a function:

int solution(int A[], int N);

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
the function should return 1, as explained above. Given array A such that:

  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

*/

int cmp( const void *a, const void *b){
    
    return *(int*)a - *(int*)b;
}

int solution(int A[], int N) {
    
    if(N == 0 || N == 1 || N == 2){
        return 0;
    }
    
    qsort(A, N ,sizeof(int), cmp);
    
    for(int i = 0; i < N-2; i++){
        if(A[i] > 0 ){
           if(A[i]+ A[i+1] > 0 && A[i] + A[i+1] > A[i+2]) {
             return 1;
           }
           if(A[i] == A[i+1] && A[i] == A[i+2]){
              return 1;
           } 
        }
    }
    
    return 0;
}

#define SIZE 6

int main(){
    
    int arr_init[SIZE] = {10,2,5,1,8,20};
    
    int result  = solution(arr_init, SIZE);
    
    printf("is triangular triplet = %d \n", result); 
}
