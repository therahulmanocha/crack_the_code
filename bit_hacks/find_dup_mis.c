/* Find Missing number and duplicate number in array */
/* Source : techiedelight */
/*
Given an array 1:n, with 1 duplicate element and 1 missing element
Find the duplicate and missing element using XOR

Example : [4,5,3,2,4]
n = 5
Dup = 4
Mis = 1
*/

#include <math.h>

int* findDupMis(int *arr, int n){
    
// take XOR of all array elements from index [0 to n-1] 
	// and all numbers in range [1 to n]
	int res = n;
	for (int i = 0; i < n; i++)
		res = res ^ arr[i] ^ i;

	// x, y stores the duplicate element and missing number
	int x = 0, y = 0;

	// res stores (x ^ y)
	// find position of the rightmost set bit in res
	int k = log2(res & -res);

	// split the array into two sub-arrays
	for (int i = 0; i < n; i++)
	{
		// array elements that have k'th bit 1
		if (arr[i] & (1 << k))
			x = x ^ arr[i];

		// array elements that have k'th bit 0
		else
			y = y ^ arr[i];
	}

	// split the range [1-n] into two sub-range
	for (int i = 1; i <= n; i++)
	{
		// number i have k'th bit 1
		if (i & (1 << k))
			x = x ^ i;

		// number i have k'th bit 0
		else
			y = y ^ i;
	}
    
    int *out = malloc(sizeof(int)*2);
    out[0] = x;
    out[1] = y;
    return out;
}
int main(){
    
    int arr[] = {4,3,5,2,4};
    int size = sizeof(arr)/sizeof(int);
    
    int *out;
    out = findDupMis(arr,size);
    
    printf("Dup = %d, Mis = %d\n",out[1],out[0]);
    return 0;
}
