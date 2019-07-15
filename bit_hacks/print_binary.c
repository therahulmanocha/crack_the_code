/* print binary representation of INT */

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
  
  int main(){
     int n = 0x001234ab;
     
     printf("input n = ");
     PRINT_WORD(n);
     printf("\n");
     
     return 0;
  }
