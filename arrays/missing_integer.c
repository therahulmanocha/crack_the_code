/*

Source: Codility

Write a function:

int solution(int A[], int N);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

*/

// This implementation uses very basic Hash table for achieve O(n) time complexity.
// But this implementation has O(n) space complexity as well. There can be a better solution with O(1) space complexity

#include <stdio.h>

#define TABLE_SIZE 2097353
#define TWO_COMPLEMENT 2097152

// Hash function for integers.
static int hash(int key) {
     if(key >= 0){
       return (key % TABLE_SIZE);
     }
     else{
       key = TWO_COMPLEMENT + key;
       return (key % TABLE_SIZE);
     }
}


void insert(int *record_table,int value){
     int idx = hash(value);
     if( record_table[idx] != value){
         record_table[idx] = value;
     }
}

int search(int *record_table,int value) {
   int idx = hash(value);
   if (record_table[idx] == value ) {
        return 1;
   }
   else {
        return 0;
   }
}

int solution(int A[], int N) {
    if(N == 1 ){
      if( A[0] != 1){
         return 1;
       }
      else{
        return 2;
      }
    }
    int *record_table;
    record_table = malloc(sizeof(record_table)*TABLE_SIZE);
    
    for(int i = 0; i < N; i++){
        insert(record_table,A[i]);
    }
    
    for(int i = 1; i <= N ; i++){
        if(!search(record_table, i)){
            return i;
        }
    }
    
    return N+1;
}



#define SIZE 6

int main(){
    
    int arr_init[SIZE] = {1,3,6,4,1,2};
    
    int result  = solution(arr_init, SIZE);
    
    printf("Missing Integer = %d \n", result); 
}
