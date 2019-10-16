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

## 3. Interview Coding Questions
Following is a compilation of Interview problems asked in Firmware Interviews at Amazon, FB, Xilinx, Samsung, Apple

1. Find the compiler output:
     int main()\
     {\
         int *a;\
         a = 0;\
     }\
     **Solution** : No Memory allocated for pointer 'a' , so compiler throws error.\

2. Output of following code:\
     void foo(){\
         static int b = 10;\
         printf("%d , ++b);\
     }\
     int main(){\
          for(int i = 0; i < 10; i++){\
              foo();\
          }\
     }\
     **Solution**: 11 12 13 14 ... 20\
3. Problem with this code:\
     void foo(const int &b){\
          b++;\
     }\
     int main(){\
          foo(25);\
     }\
     **Solution** : b is const , so foo cannot increment b, compiler throws error\
     
 4.  What will compiler output: \
     int *foo(){ \
        int x = 25; \
        x++; \
        return &x; \
     }\
     int main(){ \
        int *p;\
        p = foo(); \
        printf("%d\n", *p);\
     }\
     **Error** : Load of Null pointer of type INT
     
 5. Problem : Two Sorted Arrays a1 = [1 2 3 3 4 5 7 7 8], a2 = [2 4 5 6 8 9 9 10] \
              Combine these two arrays , such that output array is also sorted \
     **Solution** : 1. Solve by traversing the arrays using two pointers and filling in a new array. \
                    2. Hash Table can work, if range of arrays elements are known. Maintain count of array elements in hash table. \
 
 6. Problem : Two Sorted Arrays a1 and a2, find the intersection of these arrays. \
              If no intersection return NULL \
    **Solution** : 1. Use two pointers to traverse both arrays and store the same elements in a return array \
                   2. Take care of duplicate elements in both arrays, by detecting duplication and skipping all duplicates \
                   
 7. Problem : Sort an array of 4 numbers using a function which gives only min and max \
    **Solution** : See checked in Code \
    
 8. Problem : Multiply 16 bit integers using 8 bit multipliers \
    **Solution** : See checked in Code \
 
 9. Problem : For a given array, return the an array where each element is product of all elements in input array except the element at that index \
    Solve this in linear time complexity O(n) \
    Example : Input : [1,2,3,4,5] -> Output : [120,60,40,30,24] \
    **Solution** : See checked in Code \
 


    

