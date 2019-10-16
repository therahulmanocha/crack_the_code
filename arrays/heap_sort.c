/* Sort the array using heap sort */


void print_arr(int *arr, int size){
     for(int i = 0; i < size; i++){
       printf("%d  ", arr[i]);    
    }
       printf("\n");
}

void heapify(int *arr, int size , int i){
    
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l < size && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < size && arr[r] > arr[largest]){
        largest = r;
    }
    //print_arr(arr, size);
    
    if(largest != i){
        
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, size, largest);
        
    }
}

void heapsort(int* arr, int size){
    
    //heapify the array -> bring largest samples to the front
    for(int i = size/2 -1 ; i >=0 ; i--){
        heapify(arr, size, i);
    }
    //print_arr(arr, size);
    // move largest elements to the end of the array and heapify rest of the array
    for(int i = size-1; i>=0; i--){
        //swap largest and end elements
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        //
        heapify(arr, i, 0);
    }
}


int main(void) {
    printf("heap sort\n");
    int arr[] = {9,1,2,5,6,11,7,10,4,3};
    int size = sizeof(arr)/sizeof(int);
    
    heapsort(arr, size);
    print_arr(arr, size);
    printf("\n");
    
    return 0;
}
