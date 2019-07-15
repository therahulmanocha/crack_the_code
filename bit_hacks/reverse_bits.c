/* Reverse bits of a 32 bit unsigned Integer */
/* Source : Leetcode Easy */
/* 
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 
represents the unsigned integer 43261596, so return 964176192 which its
binary representation is 00111001011110000010100101000000.
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NIB_PATTERN " %c%c%c%c "
#define NIB_TO_BINARY(byte)  \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
#define PRINT_WORD(word) \
  printf(NIB_PATTERN,NIB_TO_BINARY(word)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 4)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 8)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 12)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 16)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 20)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 24)); \
  printf(NIB_PATTERN,NIB_TO_BINARY(word >> 28)); 
  

int strbin2i(const char* s) {
  register unsigned char *p = s;
  register unsigned int   r = 0;

  while (p && *p ) {
    r <<= 1;
    r += (unsigned int)((*p++) & 0x01);
  }

  return (int)r;
}
//reverse bits using strings
uint32_t reverseBits0(uint32_t n) {
    
    char *buffer;
    buffer = calloc(33,sizeof(char));
    buffer[32] = '\0';
    int i = 0;
    while(n){
        buffer[i++] = n & 1 ? '1' : '0';
        n = n/2;
    }
    while(i < 32){
        buffer[i++] = '0';
    }
    
    return strbin2i(buffer);
}
//reverse bits without strings
uint32_t reverseBits1(uint32_t n){
    
    uint32_t rev_n = 0;
    uint32_t bitcount = 0;
    while(n){
        if(n & 1){
            // shift by 31 only possibe with uint32_t
            rev_n |= ((uint32_t)1 << (31-bitcount)); 
        }
        bitcount++;
        n = n/2;
    }
    
    return rev_n;
}

int main() {
    
    int n = 0x001234ab;
    uint32_t rev0_n = reverseBits0(n);
    uint32_t rev1_n = reverseBits1(n);
    printf("input n = ");
    PRINT_WORD(n);
    printf("\n");
    printf("reverse0 n = ");
    PRINT_WORD(rev0_n);
    printf("\n");
    printf("reverse1 n = ");
    PRINT_WORD(rev1_n);
    printf("\n");
    
    return 0;
}
