




int **merge_list(int **list1, int Size, int *outSize){
    
    int **list2 = malloc(sizeof(int *) * Size);
    int count = 0;
    list2[count] = malloc(sizeof(int) * 2);
    list2[count][0] = list1[count][0];
    list2[count][1] = list1[count][1];
    
    int pmax = list2[count][1];
    int pmin = list2[count][0];
    
    for(int i = 1; i < Size; i++){    
           int cmin = list1[i][0];
           int cmax = list1[i][1];
           if(cmin < pmax && cmax <= pmax){
               continue;
              // printf("Case0 \n");
           }
           else if(cmin < pmax && cmax > pmax){
               list2[count][1] = cmax;
               pmax = cmax;
               //printf("Case1 \n");
           }
           else if(cmin > pmax){
               count++;
               list2[count] = malloc(sizeof(int) * 2);
               list2[count][0] = cmin;
               list2[count][1] = cmax;
               pmin = cmin;
               pmax = cmax;
              // printf("Case2 \n");
           }  
    }
    
    *outSize = count+1;
    return list2;
    
}

#define SIZE 5

int main(void) {
    int arr_init[SIZE][2] = {{1,5},{2,7},{9,12},{10,14},{13,15}};
    
    int **arr;
    arr = (int **)malloc(sizeof(int *)*SIZE);
    
    for(int i = 0; i < SIZE; i++){
        *(arr + i) = malloc(sizeof(int) * 2);
        arr[i][0] = arr_init[i][0];
        arr[i][1] = arr_init[i][1];
    }
    int *outsize = malloc(sizeof(int));
    
    int **list2 = merge_list(arr,SIZE, outsize);
    for(int i = 0; i < *outsize ; i++){
       printf("%d %d\n",*(*(list2 + i)), *(*(list2 + i) + 1));
    }
    
    return 0;
}