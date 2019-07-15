/* Modify the bitfields of given 32 bit words */
/*
Write a function : 
struct Results { int * R; int M; // Length of the array };

struct Results solution(int A[], int N, int B[], int K, int C[], int L);
that modifies the value of a bit field within a variably sized integer.  This integer is given via the zero-indexed array A consisting of N integers, each holding 32 bits. The function is expected to return the value of the resulting integer in the same format.

The zero-based, inclusive positions of the least (LSB) and most significant (MSB) bits of the bit field to modify are given via the zero-indexed array B consisting of K (always 2) integers: B[0] holds the LSB, B[1] holds the MSB. The zero-indexed array C consisting of L (always 2) integers provides a 32-bit mask of bits to be cleared in the bit field, as well as a value of bits to be set: C[0] holds the mask, C[1] holds the value.

For example, given A[0] = 0xffff00f0, N = 1, B[0] = 4, B[1] = 7, C[0] = 0xf, and C[1] = 0x5, the function is expected to return Result.R[0] = 0xffff0050 and Result.N = 1.

Notes:

-A[0] is the least significant word of A
-The input and output variably sized integers should have the same number of words.
*/

#include<stdio.h>
#include<math.h>

struct Results{
    int *R;
    int M;
};

struct Results solution(int A[], int N, int B[], int K, int C[], int L, int type) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int mask;
    int new_val;
    
    
    if( type == 1) {//Solution 1 : word wise processing
     int start_word = floor(B[0]/32);
     int end_word = floor(B[1]/32);
     if(end_word > start_word){ // change is spread across two words
       unsigned int bitcount0 = (end_word*32 -1 ) - (B[0]%32)  + 1;//bits to change in first word
       unsigned int bitcount1 = B[1]%32 + 1;//  bits to change in second word
       unsigned int mask0 = (unsigned int)(pow(2,bitcount0) - 1);//chunk of mask for first word
       unsigned int mask1 = (unsigned int)(pow(2,bitcount1) - 1);// chunk of mask for second word
       // First word change
       mask = ~(((unsigned int)C[0] & mask0) << B[0]%32); 
       new_val = ((unsigned int)C[1] & mask0) << B[0]%32;
       A[start_word] = (A[start_word] & mask ) | new_val;
       //Second word change
       mask = ~(((unsigned int)C[0] >> bitcount0) & mask1);
       new_val = ((unsigned int)C[1] >> bitcount0) & mask1;
       A[end_word] = (A[end_word] & mask ) | new_val; 
     }
     else{// change in contained in a single word
       mask = ~((unsigned int)C[0] << B[0]%32 );
       new_val = (unsigned int)C[1] << B[0]%32 ;        
       A[start_word]  = (A[start_word] & mask) | new_val;
     }
    }
    else if (type == 0){
     //Solution 0 : bitwise processing : loop count max = 32
     for(int i = B[0]; i <= B[1]; i++){
        
        unsigned int maskbit = ~(((unsigned int)C[0] & 1) << i%32 );
        unsigned int valbit = ((unsigned int)C[1] & 1) << i%32;
        int idx = floor(i/32);
        A[idx] = (A[idx] & maskbit ) | valbit;
        //printf("mask = %u, valbit = %u, idx = %d\n", maskbit,valbit,idx);
        C[0]  = C[0] >> 1;
        C[1]  = C[1] >> 1;
     }
    }
    result.R = A;
    result.M = N;
    return result;
}


int main(void) {
    #define TC 0 // testcase type
    int type = 0; // bitwise or wordwise 
   
    #if TC
      int A[] =  {0xffff00f0};
      int B[] =  {4,7};
      int C[] =  {0xf,0x5};
    #else
      int A[] = {0xffffffff , 0xffffffff, 0xffffffff};
      int B[] = {28,59};
      int C[] = {0xffffffff, 0xabcdef12};
    #endif
    
    int N = sizeof(A)/sizeof(int);
    int L = 2;
    int K = 2;
    struct Results result;
    result  = solution(A,N,B,K,C,L,type);
    for(int i = 0; i < result.M; i++){
        printf("Word %d : %x , %d \n",i,result.R[i], result.R[i]);
        
    }
    
    
    return 0;
}

