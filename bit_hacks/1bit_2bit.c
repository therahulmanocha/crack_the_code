/* Determine if last character is 1bit of 2bit */
/* Source : Leetcode */

/*
We have two special characters. The first character can be represented by one bit 0. 
The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits.
Return whether the last character must be a one-bit character or not. 
The given string will always end with a zero.
Example : [1 1 0]
Output : True
 
Example : [1 1 1 0]
Output : False
*/


bool isOneBitCharacter(int* bits, int bitsSize){
    
    int count = 0;
    
    while(count < bitsSize-1){
         
        if( bits[count] == 0){
            count++;
        } 
        else if(bits[count]  == 1 ){
            count += 2;
        }
        
    }
    if(count == bitsSize ){
        return false;
    }
    else{
        return true;
    }
    

}


int main(){
    int bits[] = {1,0,0};
    int size = 3;
    printf("%s\n", isOneBitCharacter(bits, size) ? "true" : "false");
    
    int bits0[] = {1, 1, 1, 0};
    size = sizeof(bits0)/sizeof(int);
    printf("%s\n",isOneBitCharacter(bits0, size) ? "true" : "false");

    return 0;
    
}
