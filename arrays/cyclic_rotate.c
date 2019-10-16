/* 
Codility : https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Assume that the following declarations are given:

struct Results {
  int * A;
  int N; // Length of the array
};

Write a function:

struct Results solution(int A[], int N, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]

*/

struct Results {
    int *A;
    int N;
};

struct Results solution(int A[], int N, int K) {
    struct Results result;
    
    if(N == 0 || N == 1 || N == K){
         result.A = A;
         result.N = N;
         return result;
    }
    
    if(K > N){
      K = K % N;
    }
    
    int *Arot = malloc(sizeof(int)*N);
    
    //copy end part of A to Arot
    for(int i = 0; i < K; i++){
        Arot[i] = A[N - K + i];
    }
    
    for(int i = N-1; i >= K ; i--){
        Arot[i] = A[i - K];
    }
    
    result.A = Arot;
    result.N = N;
    return result;
}

void print_arr(int A[], int N){
    for(int i = 0; i < N; i++){
        printf("%d,", A[i]);
    }
    printf(" \n");
}

#define SIZE 9
int main(){
    
    int arr_init[SIZE] = {1,2,3,4,5,6,7,8,9};
    print_arr(arr_init, SIZE);
    
    int rotate = 4;
    struct Results result; 
    result  = solution(arr_init, SIZE , rotate);
    
    print_arr(result.A, SIZE);
}
