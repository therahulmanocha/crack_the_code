/*
Problem 6 : Given two sorted Arrays, find the intersection of these arrays
Also, make sure no duplicates occur in output
Example : arr0 = [1,4,4,5,7,10] , arr1 = [1,2,3,4,10]
Output : [1,4,10]
*/

int *intersect(const int *arr0, int size0, const int *arr1, int size1, int *size2){
    
    if(!arr0 || !arr1){
        return NULL;
    }
    if(size0 == 0 || size1 == 0){
        return NULL;
    }
    int N = size0 < size1 ? size0 : size1;
    int count = 0;
    int *retArr = malloc(sizeof(int) * N);
    int idx0 = 0;
    int idx1 = 0;
    int pre0 = arr0[0] - 1;
    int pre1 = arr1[0] - 1;
    
    while(idx0 < size0 && idx1 < size1){
        
        if(arr0[idx0] == pre0){
            idx0++;
        }
        else if(arr1[idx1] == pre1){
            idx1++;
        }
        else if(arr0[idx0] < arr1[idx1]){
            pre0 = arr0[idx0];
            idx0++;
        }
        else if(arr0[idx0] > arr1[idx1]){
            pre1 = arr1[idx1];
            idx1++;
        }
        else{
            retArr[count++] = arr0[idx0];
            pre0 = arr0[idx0];
            pre1 = arr1[idx1];
            idx0++;
            idx1++;
        }
    }
    
    *size2 = count;
    return retArr;
     
}

int main(void) {
    const int buf0[] = { 1, 5 , 6, 6 , 6, 7 , 9 , 9, 9, 10,89};
    const int buf1[] = { 2, 6, 6, 6, 9, 13 , 15, 20, 44,44,89, 89};
    
    int size0 = sizeof(buf0)/sizeof(int);
    int size1 = sizeof(buf1)/sizeof(int);
    
    int *retArr;
    int *retSize = malloc(sizeof(int));
    
    retArr = intersect(buf0, size0, buf1, size1, retSize);
    
    for(int i = 0; i < *retSize; i++){
        printf("%d ", retArr[i]);
    }
    
    return 0;
}
