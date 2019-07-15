/* Bitwise and of all numbers in given range */
/* Source : Leetcode */

/* 
Given a range [m, n] where 0 <= m <= n <= 2147483647
return the bitwise AND of all numbers in this range, inclusive
*/

int rangeBitwiseAnd(int m, int n){
    // keep doing AND op, till the n > m
    while(n > m){
        n = n & (n-1);
    }
    return n;
}

int main(){
    
    int m = 5;
    int n = 7;
    
    int x = rangeBitwiseAnd(m,n);
    printf("bitwise And = %d\n", x);
    
    m = 2147483646;
    n = 2147483647;
    printf("bitwise And = %d\n", rangeBitwiseAnd(m,n));
    
    return 0;
}
