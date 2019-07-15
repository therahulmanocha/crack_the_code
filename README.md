# crack_the_code
Coding interview Questions and Solutions

This repository is created with the intent of sharing easy/medium/hard and relevant coding problems for cracking software/firmware coding challenges. Following are the types of coding questions covered in this repo so far.

1. Bit Manipulation Questions:
     1. Check if n is Odd/Even : **(n & 1)**
     2. Check if a and b have opposite sign : **(a ^ b > 0)**
     3. Count number of 1s in n :  **n = n & (n-1) , count++**
     4. Add 1 to integer n : **-~n**
     5. Swap two number x and y : **x = x ^ y; y = x ^ y; x = x ^ y**
     6. Mask bit k of x : **x & ~(1 << (k-1))**
     7. Set  bit k of x : **x | (1 << (k-1))**
     8. Toggle bit k of x : **x ^ (1 << (k-1))**
     9. Check if x is power of 2 : **n & (n-1) == 0**
     10. Find rightmost bit position: **n = n ^ (n & (n-1)) , while(n){ n >> 1, pos++} , return pos**
     11. Find absolute of n without branching : **mask = n >> 31, n = (n + mask) ^ mask**
     
     


Coding problems have been picked from following sources:

1. LeetCode
2. 
