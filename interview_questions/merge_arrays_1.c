/* 
   Problem 5 
   Given : Two sorted arrays a1, a2
   Return an array which is a combination of these two and sorted
   
*/

int *merge(const int *arr0, int size0, const int *arr1, int size1, int *retSize){
    
    if(!arr0 || !arr1){
        return NULL;
    }
    if(size0 == 0 || size1 == 0){
        return NULL;
    }
    int N = size0 + size1;
    int *retArr = malloc(sizeof(int) * N);
    
    int idx0 = 0;//index for arr0
    int idx1 = 0; // index for arr1
    int count = 0; // index for retArr
    
    while(idx0 < size0 && idx1 < size1){
        
        if(arr0[idx0] <= arr1[idx1]){
            retArr[count++] = arr0[idx0++];
        }
        else {
            retArr[count++] = arr1[idx1++];
        }
    }
    
    while(idx0 < size0){
        retArr[count++] = arr0[idx0++];
    }
    while(idx1 < size1){
        retArr[count++] = arr1[idx1++];
    }
    
    *retSize = count;
    return retArr;
}

#define SIZE0 6
#define SIZE1 9

int main(){
    
    int arr0[SIZE0] = {1,5,7,8,10,12};
    int arr1[SIZE1] = {3,3,5,5,5,6,10,11,15};
    
    int *list0 = malloc(sizeof(int) * SIZE0);
    int *list1 = malloc(sizeof(int) * SIZE1);
    
    for(int idx0 = 0; idx0 < SIZE0; idx0++){
        list0[idx0] = arr0[idx0];
    }
    
    for(int idx1 = 0; idx1 < SIZE1; idx1++){
        list1[idx1] = arr1[idx1];
    }
    
    int *retArr;
    int *retSize = malloc(sizeof(int));
    
    retArr  = merge(list0, SIZE0, list1, SIZE1, retSize);
     
    for(int k = 0; k < *retSize; k++){
        printf("%d ", retArr[k]);
    }
     
    printf(" \n");
    
}
