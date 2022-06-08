/* Create all unique subsets of given array
Assume array has unique elements.
*/


typedef struct{
    int count;
    int *set;
}t_superset;

t_superset* findPowerSet(int *arr, int size, int* retsize)
{
    
    // assume arr elements are unique
    // find all sets by using binary representation of numbers from 0 : size
    
    int setsize = 1 << size;
    
    t_superset* powerset;
    powerset = (t_superset *)malloc(sizeof(t_superset)*setsize);
    for(int i = 0; i < setsize; i++)
    {
        powerset[i].set = (int *)malloc(sizeof(int) * size);
    }
    
    for(int subset = 1; subset < setsize ; subset++)
    {
        int count = 0;
        for(int idx = 0; idx < size; idx++)
        {
            if( subset & (1 << idx)) // if bit pos idx is set in subset
            {
                powerset[subset].set[count++] = arr[idx];
                
            }   
        }
        powerset[subset].count = count;
    }
    
    *retsize = setsize;
    return powerset;
}



int main()
{
    int size = 4;
    int arr[] = {5,3,0,1};
    
    t_superset* powerset;
    
    int *retsize = (int *) malloc(sizeof(int));
    
    powerset = findPowerSet(arr,size,retsize);
    
    for(int idx = 0; idx < *retsize; idx ++)
    {
        printf("[ ");
        for(int s = 0; s < powerset[idx].count; s++)
        {
            
            printf("%d,",powerset[idx].set[s]);
            
        }
        printf(" ];\n");
    }
    
}
