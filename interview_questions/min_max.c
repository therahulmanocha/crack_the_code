/* 
Problem 7 :
Sort an array of 4 numbers using a function that only return minimum and maximum of given 2 numbers
Example : Input [1,7,5,10] -> Output : [10,7,5,1]

*/


void minmax(int *a, int *b){
   
    int max = *a ^ ((*a ^ *b) & -(*a < *b));
    int min = *b ^ ((*a ^ *b) & -(*a < *b));
    *a = max;
    *b = min;
}


int main() {
    int nums[4] = {0,2,5,10};
    
    minmax(&nums[0], &nums[1]);
    minmax(&nums[2], &nums[3]);
    
    
    minmax(&nums[0], &nums[2]);
    minmax(&nums[1], &nums[3]);
    
    minmax(&nums[0], &nums[3]);
    minmax(&nums[1], &nums[2]);
    
    printf("%d %d %d %d\n",nums[0],nums[1],nums[2],nums[3]);
    return 0;
}
