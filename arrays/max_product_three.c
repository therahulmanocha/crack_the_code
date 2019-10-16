/* Find Max product of 3 numbers in an unsorted array
   Source : Codility : https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
   Example : Input : [-3, 1,2,-2,5,6]
             Output : 2 x 5 x 6 = 60 -> max product
*/


int cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    
    if(N == 3){
        return A[N-3] * A[N-2] * A[N-1];
    }
    qsort(A, N, sizeof(int), cmp);
    
    if( A[N-3] * A[N-2] * A[N-1] < A[0] * A[1] * A[N-1]) {
        return A[0] * A[1] * A[N-1];
    }
  
     return A[N-3] * A[N-2] * A[N-1];   
}

#define SIZE 6

int main(){
    
    int arr_init[SIZE] = {-3,1,2,-2,5,6};
    
    int max_product = solution(arr_init, SIZE);
    
    printf("max product = %d\n", max_product);
    
    
}
