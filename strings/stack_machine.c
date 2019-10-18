/*
A word machine is a system that performs a sequence of simple operations on a stack of integers. Initially the stack is empty. The sequence of operations is given as a string. Operations are separated by single spaces. The following operations may be specified:

an integer X (from 0 to 220 − 1): the machine pushes X onto the stack;
"POP": the machine removes the topmost number from the stack;
"DUP": the machine pushes a duplicate of the topmost number onto the stack;
"+": the machine pops the two topmost elements from the stack, adds them together and pushes the sum onto the stack;
"-": the machine pops the two topmost elements from the stack, subtracts the second one from the first (topmost) one and pushes the difference onto the stack.
After processing all the operations, the machine returns the topmost value from the stack.

The machine processes 20-bit unsigned integers (numbers from 0 to 220 − 1). An overflow in addition or underflow in subtraction causes an error. The machine also reports an error when it tries to perform an operation that expects more numbers on the stack than the stack actually contains. Also, if, after performing all the operations, the stack is empty, the machine reports an error.

For example, given a string "13 DUP 4 POP 5 DUP + DUP + -", the machine performs the following operations:

  operation | comment             | stack
 --------------------------------------------------
            |                     | [empty]
 "13"       | push 13             |
            |                     | 13
 "DUP"      | duplicate 13        |
            |                     | 13, 13
 "4"        | push 4              |
            |                     | 13, 13, 4
 "POP"      | pop 4               |
            |                     | 13, 13
 "5"        | push 5              |
            |                     | 13, 13, 5
 "DUP"      | duplicate 5         |
            |                     | 13, 13, 5, 5
 "+"        | add 5 and 5         |
            |                     | 13, 13, 10
 "DUP"      | duplicate 10        |
            |                     | 13, 13, 10, 10
 "+"        | add 10 and 10       |
            |                     | 13, 13, 20
 "-"        | subtract 13 from 20 |
            |                     | 13, 7
Finally, the machine will return 7.

Given a string "5 6 + -", the machine reports an error, since, after the addition, there is only one number on the stack, but the subtraction operation expects two.

Given a string "3 DUP 5 - -", the machine reports an error, since the second subtraction yields a negative result.

Write a function:

int solution(char *S);

that, given a string S containing a sequence of operations for the word machine, returns the result the machine would return after processing the operations. The function should return −1 if the machine would report an error while processing the operations.

For example, given string S = "13 DUP 4 POP 5 DUP + DUP + -" the function should return 7, as explained in the example above. Given string S = "5 6 + -" or S = "3 DUP 5 - -" the function should return −1.

Assume that:

the length of S is within the range [0..2,000];
S is a valid sequence of word machine operations.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

*/

#include <string.h>
#include <stdio.h>

#define MAX_INT 1048575
#define SIZE 500

int STACK_SIZE = SIZE;
int *stack;
volatile int stackptr  = -1; 

inline int isempty(){
    return stackptr == -1;
}
inline int isfull() {
    return stackptr == STACK_SIZE-1;
}

int  push(int a){
    if(!isfull()){
        stack[++stackptr] = a;
        return 1;
    }
    return -1;
}

int pop(){
    if(!isempty()){
        return stack[stackptr--];
    }
    return -1;
}

int dup(){
     if(!isfull() && !isempty()){
         stack[stackptr+1] = stack[stackptr];
         stackptr++;
         return 1;
     }
     return -1;
}

int add(){
    if(!isfull() && !isempty() && stackptr >= 1){
        stack[stackptr-1] = stack[stackptr] + stack[stackptr-1];
        stackptr--;
        if(stack[stackptr] > MAX_INT){
            return -1;
        }
        return 1;
    }
    return -1;
}

int sub(){
    if(!isfull() && !isempty() && stackptr >= 1){
        stack[stackptr-1] = stack[stackptr] - stack[stackptr-1];
        stackptr--;
        if(stack[stackptr] < 0){
            return -1;
        }
        else{
            return 1;
        }
    }

    return -1;
}

void print_stack(){
    printf("stack:\n");
    for(int i = 0; i <= stackptr; i++){
        printf("%d: %d ", i, stack[i]);
    }
    printf("\n");
}

int run_code(char *S){
    
    int ret;
    if(!strcmp(S, "DUP")){
         ret = dup();
         //printf("opcode DUP\n");
    }
    else if (!strcmp(S , "POP")){
        ret = pop();    
        //printf("opcode POP\n");
    }
    else if ( !strcmp(S, "+")){
        ret = add();
        //printf("opcode ADD\n");
    }
    else if (!strcmp(S, "-")){
        ret = sub();
        //printf("opcode SUB\n");
    }
    else  {
            int val = atoi(S);
            //printf("push : %d\n", val);
            if(val <= MAX_INT){
              ret = push(val);
              //printf("opcode PUSH\n");
            }
            else{
              ret = -1;
            }
    }    
    return ret;
}
int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    int N = strlen(S);
    
    char Ops[10];// MAX < 2000/3 operations
    int opcount = 0;
    int j = 0;
    
    stack = malloc(sizeof(int) * SIZE);
    
    //get operations from string
    for (int i = 0; i <= N; i++){
        //printf("%c",S[i]);
        if(S[i] == ' ' || S[i]=='\0')
        {
            Ops[j] = '\0';
            printf("Operation %d : %s\n",opcount++,Ops);
            if(j > 0){
             int ret = run_code(Ops);
             if(ret == -1){
                 print_stack();
                 free(stack);
                 stackptr = -1;
                 return -1;
             }
            }
            j = 0;
            
        }
        else{
            Ops[j] = S[i];
            j++;
        }
    }
    print_stack();
    
    if(stackptr >= 0){
       int ret_val = stack[stackptr];
       free(stack);
       stackptr = -1;
       return ret_val;
    }
    else{
        return -1;
    }
}

int main(void){
    
    char *S;
    S = " 13 DUP 4 POP 5 DUP + DUP + - ";
   
    int result = solution(S);
    printf("Stack Top : %d\n\n", result);
    
    S = "1 DUP + DUP + DUP + DUP + DUP +";
    result = solution(S);
    printf("Stack Top : %d\n", result);
    
    return 0;
}

