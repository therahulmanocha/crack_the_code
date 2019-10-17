/*
Problem 8 : Multiply two 16 bit integers , using 8 bit multipliers

*/


#include<stdio.h>

void negate(int16_t *a){
    *a = ~(*a - 1);
}

void neg32(int *a){
    *a = ~(*a) + 1;
}


int main(void) {
    int16_t a = 0xfabc;
    int16_t b = 0x0101;
    
    int ref = a*b;
    printf("a = %.4x, b = %.4x, a*b = %.8x\n",a,b, ref);
    
    bool asign = 0;
    if(a < 0){
        negate(&a);
        asign = 1;
    }
    bool bsign = 0;
    if(b < 0){
        negate(&b);
        bsign = 1;
    }
    
    uint8_t a0 = a & 0x00ff;
    uint8_t a1 = (a >> 8) & 0x00ff;
    uint8_t b0 = b & 0x00ff;
    uint8_t b1 = (b >> 8) & 0x00ff;
   
    uint16_t a0b0 = a0 * b0;
    uint16_t a1b0 = a1 * b0;
    uint16_t a0b1 = a0 * b1;
    uint16_t a1b1 = a1 * b1;
    printf("a0 = %.2x, a1 = %.2x\n",a1,a0);
    printf("b0 = %.2x, b1 = %.2x\n",b1,b0);
    printf("a0b0 = %.4x , a1b0 = %.4x , a0b1 = %.4x , a1b1 = %.4x\n", a0b0, a1b0, a0b1, a1b1);
    
    uint32_t out = a0b0 + ((a1b0 + a0b1)<<8) + (a1b1<<16);
    
    if(asign^bsign){
        neg32(&out);
    }
    
    printf("final output = %.8x\n",out);
}
    
