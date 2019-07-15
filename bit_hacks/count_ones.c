/* Count number of 1's */
/* Source : Leetcode */
/*
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num 
calculate the number of 1's in their binary representation 
and return them as an array.
*/

/* 
For every num, add the LSB with the number of 1's in num >> 1
*/
int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int *nums = malloc(sizeof(int) * (*returnSize));
    nums[0] = 0;
    if (num <= 0) {
        return nums;
    }   
    nums[1] = 1;
    if (num <= 1) {
        return nums;
    }   
    for (int i = 2; i <= num; i++) {
	    // sum of one in last bit and previous bits
        nums[i] = (i & 0x1) + nums[i >> 1];
    }   
    return nums;
}


int main(){
    
    int *arr;
    int n = 20;
    int *size  = malloc(sizeof(int));
    arr = countBits(n, size);
    printf("[ ");
    for(int i = 0; i < *size; i++){
         printf("%d ",arr[i]);
    }
    printf("]\n");
    return 0;
    
}

