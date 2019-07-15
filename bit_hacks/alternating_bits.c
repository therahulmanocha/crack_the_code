/* Check if a number has alternating bits */
/* Source Leetcode */
/*
Given a positive integer, 
check whether it has alternating bits: 
namely, if two adjacent bits will always have different values
*/


bool hasAlternatingBits(int n){
    if(n == 0){
        return true;
    }
    int curr_bit = n & 1;
    while(n > 0){
        n = n/2;
        if((n & 1) != !curr_bit){
            return false;
        }
        else{
            curr_bit = !curr_bit;
        }
    }
    return true;
}


int main(){
    
    printf("%s\n", hasAlternatingBits(10) ? "true" : "false");
    printf("%s\n", hasAlternatingBits(20) ? "true" : "false");

    return 0;
    
}
