/* Merge 2 lists of intervals */
/* Example : list 1 : {{1,5},{2,7},{9,12},{10,14},{13,15}}
             list 2 : {{3,8},{12,17},{18,20},{19,21}}
             Output : {{1,8}, {9,17}, {18,21}}
*/

#include<stdio.h>

int **merge_list(int **list1, int Size1, int **list2, int Size2, int *outSize){
    int **retList = malloc(sizeof(int *) * (Size1+Size2));
    int count = 0;
    retList[count] = malloc(sizeof(int) * 2);
    retList[count][0] = list1[count][0];
    retList[count][1] = list1[count][1];
    
    int pmax = list1[count][1];
    int pmin = list1[count][0];
    int cmin = 0;
    int cmax = 0;
    for(int i = 0, j= 0; i < Size1 || j < Size2;){  
        
        if(i < Size1 && j < Size2){
           if(list1[i][0] < list2[j][0]){
            cmin = list1[i][0];
            cmax = list1[i++][1];
           }
           else{
            cmin = list2[j][0];
            cmax = list2[j++][1];
           }
        }
        else if(j < Size2){
            cmin = list2[j][0];
            cmax = list2[j++][1]; 
        }
        else if(i < Size1){
            cmin = list1[i][0];
            cmax = list1[i++][1];
        }
        else{
            break;
        }
        //printf("cmin = %d, cmax = %d\n", cmin, cmax);
        //printf("pmin = %d, pmax = %d\n", pmin, pmax);
           if(cmin < pmax && cmax <= pmax){ 
               //printf("Case0 \n");
               continue;
           }
           else if(cmin <= pmax && cmax > pmax){
               retList[count][1] = cmax;
               pmax = cmax;
               //printf("Case1 \n");
           }
           else if(cmin > pmax){
               count++;
               retList[count] = malloc(sizeof(int) * 2);
               retList[count][0] = cmin;
               retList[count][1] = cmax;
               pmin = cmin;
               pmax = cmax;
               //printf("Case2 \n");
           }  
    }
    
    *outSize = count+1;
    return retList;
    
}

#define SIZE1 5
#define SIZE2 4

int main(void) {
    
    int arr1_init[SIZE1][2] = {{1,5},{2,7},{9,12},{10,14},{13,15}};
    int arr2_init[SIZE2][2] = {{3,8},{12,17},{18,20},{19,21}};
    
    int **arr1;
    arr1 = (int **)malloc(sizeof(int *)*SIZE1);
    
    for(int i = 0; i < SIZE1; i++){
        *(arr1 + i) = malloc(sizeof(int) * 2);
        arr1[i][0] = arr1_init[i][0];
        arr1[i][1] = arr1_init[i][1];
    }
    
    for(int i = 0; i < SIZE1 ; i++){
       printf("%d,%d  ",*(*(arr1 + i)), *(*(arr1 + i) + 1));
    }
     
    printf("\n");
    
    int **arr2;
    arr2 = (int **)malloc(sizeof(int *)*SIZE2);
    for(int i = 0; i < SIZE2; i++){
        *(arr2 + i) = malloc(sizeof(int) * 2);
        arr2[i][0] = arr2_init[i][0];
        arr2[i][1] = arr2_init[i][1];
    }
    
    for(int i = 0; i < SIZE2 ; i++){
       printf("%d,%d  ",*(*(arr2 + i)), *(*(arr2 + i) + 1));
    }
    
    printf("\n");
    int *outsize = malloc(sizeof(int));
    
    int **list2 = merge_list(arr1,SIZE1,arr2,SIZE2, outsize);
    for(int i = 0; i < *outsize ; i++){
       printf("%d,%d  ",*(*(list2 + i)), *(*(list2 + i) + 1));
    }
    
    return 0;
}
