/* Find all numbers with prime number of set bits */
/* Source : Leetcode */

/*
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive)
having a prime number of set bits in their binary representation.
(Recall that the number of set bits an integer has is the number of 1s present when written in binary. 
For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)

Note:
L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/

/* Solution can use hash table of primes, 
since 10^6 has 23 bits and largest prime before that is 19
*/



int count_ones(int n) {
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}

int countPrimeSetBits(int L, int R){
    if(R == 2){
        return 1;
    }
    int *primes; // table of primes
    primes = calloc(20, sizeof(int));
    primes[2] = 1;
    primes[3] = 1;
    primes[5] = 1;
    primes[7] = 1;
    primes[11] = 1;
    primes[13] = 1;
    primes[17] = 1;
    primes[19] = 1;
    
    int count = 0;
    for(int i = L ; i <= R; i++){
        if(primes[count_ones(i)]){
            count++;
        }
    }
    
    return count;
}

int main(){
    printf("prime count = %d \n", countPrimeSetBits(842, 888));
    return 0;
}
