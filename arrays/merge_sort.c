/* Merge Sort Algorithm */

void merge(int *arr, int start, int middle, int end)
{
       int i = start;
       int j = middle+1;
       int *merge_arr = malloc(sizeof(int)*(end-start+1));
       int count = 0;
       while(i <= middle && j <= end ){
           if(arr[i] < arr[j]){
               merge_arr[count++] = arr[i++];
              // printf("C %d ", merge_arr[count-1]);
           }
           else{
               merge_arr[count++] = arr[j++];
              // printf("D %d ", merge_arr[count-1]);
           }
       }
       
       while(i <= middle){
           merge_arr[count++] = arr[i++];
       }
       while(j <= end){
           merge_arr[count++] = arr[j++];
       }
    
       for(int i = start; i < end+1; i++){
         arr[i] = merge_arr[i-start];
      }
       
}

void mergeSort(int *arr, int start, int end){
    // start : start idx for list to sort
    // end : end idx for list to sort
    
    // for even size, left arr size = right arr size
    // for odd  size, left arr size = right arr size + 1
    if(start < end){
     int middle = (start + end)/2;
     mergeSort(arr, start, middle);
     mergeSort(arr, middle+1, end);
     merge(arr,start,middle,end);
    }
}


int main(void) {
    printf("merge sort\n");
    int arr[] = {9,10,1,2,5,6,11,7,10,4,3};
    int size = sizeof(arr)/sizeof(int);
    
    mergeSort(arr, 0, size-1);

    for(int i = 0; i < size; i++){
       printf("%d  ", arr[i]);    
    }
    printf("\n");
    
    return 0;
}
