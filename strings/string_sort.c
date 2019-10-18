/* 
   Sort character strings using Hash. 
   ASCII has 256 characters
   use a hash table of 256 to sort any character string
*/

void string_sort(char *S){
    
    int len = strlen(S);
    
    //store the count of each char(ascii) 
    int *countArray = calloc(256,sizeof(int));
    for(int i=0; S[i]; i++){
        countArray[S[i]]++;
    }
    
    
    for(int i = 0; i < 256; i++ ){
         while(countArray[i]){
             *S = (char)i;
             S++;
            // printf("%d ",i);
             countArray[i]--;
         }
    }
     *S = '\0';    
     S -= len;

}

int main(void) {
    
    char S[] = "abdefcghxy";
    
    printf("%s\n",S);
    
    string_sort(S);
    
    printf("%s\n",S);
   
    
    return 0;
}
