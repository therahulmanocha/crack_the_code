/* compute parity using lookup table */
/* Source : techiedelight.com */
/* 5 -> even number of ones, so even parity
/* 7 -> odd number of ones, so odd parity



#define P2(n) n, n^1, n^1, n
#define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
#define FIND_PARITY P6(0), P6(1), P6(1), P6(0)
 
// lookup-table to store the parity of each index of the table
// The macro FIND_PARITY generates the table
unsigned int lookup[256] = { FIND_PARITY };
 
// Function to find parity of x
int findParity(int x)
{
 
	// assuming 32-bit(4 byte) integer, break the integer into 
	// 16-bit chunks and take their XOR
	x ^= x >> 16;
	
	// Again split 16-bit chunk into 8-bit chunks and take their XOR
	x ^= x >> 8;
	
	// Note mask used 0xff is 11111111 in binary
	return lookup[x & 0xff];
}

int main(){
    
    printf("parity = %s \n", findParity(12345) ? "odd" : "even");

    return 0;
    
}
