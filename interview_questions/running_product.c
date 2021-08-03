/*
Problem 9:
For a given array, return an array where each element is product of all elements in input array except the element at that index
Don't Use Division
Solve this in linear time complexity O(n)
Example : Input : [1,2,3,4,5] -> Output : [120,60,40,30,24]
*/


int *solution(const int *arr0, int size0){
    
    if(!arr0){
        return NULL;
    }
    if(size0 == 0){
        return NULL;
    }
    
    int *retArr = malloc(sizeof(int) * size0);
    int *prod_l = malloc(sizeof(int) * size0); // store product of left elements
    int *prod_r = malloc(sizeof(int) * size0); // store product of right elements
    
    // left and right product is 1 for first and last element
    prod_l[0] = 1;
    prod_r[size0-1] = 1;
    
    //find all left products
    for(int l = 1; l < size0; l++){
        prod_l[l] = arr0[l-1] * prod_l[l-1];
    }
    //find all right products
    for(int r = size0-2; r >=0; r--){
        prod_r[r] = arr0[r+1] * prod_r[r+1];
    }
    for(int i = 0; i < size0; i++){
        retArr[i] = prod_l[i] * prod_r[i];
    }
    
    free(prod_l);
    free(prod_r);
    return retArr;
    
}


int main(void) {
    const int buf0[] = { 2,3,4,5,6}; 
    int size0 = sizeof(buf0)/sizeof(int);
    
    int *retArr;
    
    retArr = solution(buf0, size0);
    
    for(int i = 0; i < size0; i++){
        printf("%d ", retArr[i]);
    }
    
    return 0;
}
    
