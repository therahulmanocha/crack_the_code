# crack_the_code
Coding interview Questions and Solutions

This repository is created with the intent of sharing  relevant coding problems for cracking software/firmware/embedded-systems coding challenges. Following are the types of coding questions covered in this repo so far.

Coding problems have been picked from following sources:

1. LeetCode
2. Codility
3. Interviews

## 1. Bit Manipulation Questions:
  ### Basic One Liners:
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
  12. Minimum of x and y without branching : **y ^ ((x^y) & -(x < y))**
  13. Maximum of x and y without branching : **x ^ ((x^y) & -(x < y))**
  14. Find power of 2 greater than given number : **while(n & (n-1)) { n = n & n-1 }, return n << 1**
  15. Find power of 2 less than given number : **while(n & (n-1)) { n = n & n-1 }, return n**
  16. Check if n is power of 4 , only 1 set bit and set bit at even positions: **n && !(n & (n - 1)) && !(n & 0xAAAAAAAA)**
  17. Conditionally negate value without branching : **(n ^ -flag) + flag**
  
 ### Medium Difficulty Problems:   
  1. 1bit_2bit.c -> Determine if last character is 1bit of 2bit
  2. alternating_bits.c -> Check if a number has alternating bits
  4. bitflip_convert.c -> Find number of bits that need to be flipped to convert x to y
  5. bitwise_and_range.c -> Bitwise and of all numbers in given range 
  6. count_ones.c -> Count number of 1's in binary of all numbers between 0 to n
  7. findOddOccu.c -> Find Odd occuring  elements in an array
  8. find_dup_mis.c -> Find Missing number and duplicate number in array
  9. modify_bitfields.c -> Modify the bitfields of given 32 bit words
  10. parity_lookup_table.c -> compute parity using lookup table
  11. prime_number_setbits.c -> Find all numbers with prime number of set bits
  12. print_binary.c ->  print binary representation of a 32 bit number using  MACRO
  13. product_bit_count.c -> Count Bits in Product of two numbers
  14. reverse_bits.c -> Reverse bits of a 32 bit unsigned Integer
     
## 2. Array Manipulation
   Problems hand picked from Leetcode and Codility. These include basic list merging, sorting, 1D and 2D array rotation, transpose, dot product. These are must for understanding time/space complexity trade-off in solving array problems. They do not include complex data structures and DP problems, since those are rarely asked in Firmware/Embedded-systems interviews.



