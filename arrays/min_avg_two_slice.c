/*
Source : Codility : https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, 
is called a slice of array A (notice that the slice contains at least two elements). 
The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. 
To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
contains the following example slices:

slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
The goal is to find the starting position of a slice whose average is minimal.

*/

double average2(int a, int b){
    
    return (double)(a + b)/(double)(2);
}
double average3(int a, int b , int c){
    return (double)(a + b + c)/(double)(3);   
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if(N == 2){
        return 0;
    }
    
    double minval = average2(A[0],A[1]) < average3(A[0],A[1],A[2]) ? average2(A[0],A[1]) : average3(A[0],A[1],A[2]);
    int minidx = 0;
    
    for(int i = 1; i < N-2; i++)   {
        
        double local_min =   average2(A[i],A[i+1]) < average3(A[i],A[i+1],A[i+2]) ? average2(A[i],A[i+1]) : average3(A[i],A[i+1],A[i+2]);  
        
        if(local_min < minval){
            minval = local_min;
            minidx = i;
        }
        
    }
    
    double local_min = average2(A[N-2],A[N-1]);
    if(local_min < minval){
            minval = local_min;
            minidx = N-2;
    }
    
    return minidx;
    
}

#define SIZE 7

int main(){
    
    int arr_init[SIZE] = {4,2,2,5,1,5,8};
    
    int min_idx = solution(arr_init, SIZE);
    
    printf("min idx = %d\n", min_idx);
    
}
