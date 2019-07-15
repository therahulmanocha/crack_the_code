/* Find number of bits that need to be flipped to convert x to y */
/* Source : techiedelight.com */

/* Example : 
   a = 5, b = 10 
   solution : 4, since 4 bit flips converts 5 -> 10
*/

int findBits(int x, int y)
{
	// take XOR of x and y and store in n
	int n = x ^ y;
	
	// Using Brian Kernighan's algorithm to count set bits
	
	// count stores the total bits set in n
	int count = 0;

	for (; n; count++)
		n = n & (n - 1); // clear the least significant bit set
	
	return count;
}


int main(){
    printf("bit count = %d \n", findBits(5,10));
    return 0;
}
