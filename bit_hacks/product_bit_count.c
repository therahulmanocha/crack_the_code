/* Count Bits in Product */
/* Source : Codility */
/* 
Write a function:

int solution(int A, int B);

that, given two non-negative integers A and B, returns the number of bits set to 1 in the binary representation of the number A * B.

For example, given A = 3 and B = 7 the function should return 3, because the binary representation of A * B = 3 * 7 = 21 is 10101 and it contains three bits set to 1.

Assume that:

A and B are integers within the range [0..100,000,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/


#include<stdio.h>
#include<math.h>

int solution(int A, int B) {
    // write your code in C99 (gcc 6.2.0)
    //use long long int, since result can be more than 32 bits
    long int X = (long int)A * (long int)B;
    printf("A = %d, B = %d , X = %ld\n", A, B, X);
    //printf("X = %ld\n", X);
    int count = 0;
    while(X ){
       X = X & (X-1);
       count++;
    }
        
    return count;
    
}


int main(void) {
    int A = pow(10,8) - 1;
    int B = pow(10,8) - 1;
   
    int count = solution(A, B);
    printf("count = %d\n",count);
    return 0;
}
