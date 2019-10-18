/* 
Source : Leetcode
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. 
For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. 
Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false

*/

#include <string.h>

bool rotateString(char * A, char * B){
    if(!strcmp(A,B)){
        return true;
    }
    if(strlen(A) != strlen(B) || strlen(A) == 0 ) {
        return false;
    }
    
    int len = strlen(A);
    char *S = malloc(sizeof(char) * (len+1));
    
    for(int i = 1; i < strlen(A); i++){
        strncpy(S,A+i,len-i);
        strncpy(S+len-i,A,i);
        S[len] = '\0';
        if(!strcmp(S,B)){
            return true;
        }
    }
    return false;
}


int main(void) {
    char *A = "abcde";
    char *B = "abced";
    
    printf("string match = %d \n",rotateString(A,B));
    
    return 0;
}
