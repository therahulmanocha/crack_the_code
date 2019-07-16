/*Find Odd occurences of elements in an array */
/* Source : techiedelight.com */

/* 
In an array with elements between 0 to 31
find elements with odd occurences

Example : { 5,8,2,3,8,5,5,8,2,1,1,4,4 )
solution: 5, 8, 3

XOR 1<< elements for all elements, 
only ODD occuring elements will be 1 finally
*/

int* findOddOccur(int *arr, int size, int *count){
    int xor = 0;
    for(int i = 0; i < size; i++){
           // 1s at position with odd occurences
           xor ^= (1 << arr[i]);
    }
    
    int *out = malloc(sizeof(int)*size);
    *count = 0;
    for(int i = 0; i < size; i++){
        if((1 << arr[i]) & xor){
            out[(*count)++] = arr[i];
            xor ^= (1 << arr[i]);
        }
    }
    return out;
}
int main(){
    
    int arr[] = {5,8,2,3,8,5,5,8,2,1,1,4,4};
    int size = sizeof(arr)/sizeof(int);
    
    int *out;
    int *outsize = malloc(sizeof(int));
    out = findOddOccur(arr,size, outsize);
    
    for(int i = 0; i < *outsize; i++){
       printf("%d  ",out[i]);
    }
    printf("\n");
    
    return 0;
    
}
