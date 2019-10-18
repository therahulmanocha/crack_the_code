/*
Source : Codility

A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
Assume that the following declarations are given:

struct Results {
  int * A;
  int M; // Length of the array
};

Write a function:

struct Results solution(char *S, int P[], int Q[], int M);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a structure Results.

For example, given the string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N − 1];
P[K] ≤ Q[K], where 0 ≤ K < M;
string S consists only of upper-case English letters A, C, G, T.
*/

#define X 'A'
#define C 'C'
#define G 'G'
#define T 'T'
#define VAL(str) (str == X) ? 1 : (str == C) ? 2 : (str == G) ? 3 : (str == T) ? 4 : 0

#define findA(str0) strchr(str0,X) 
#define findC(str0) strchr(str0,C) 
#define findG(str0) strchr(str0,G) 
#define findT(str0) strchr(str0,T) 

int find_min( char *S, int idx0, int idx1){
       
       char *s_0;
     //  char *s_1;
       s_0 = S + idx0;
      // s_1 = S + idx1;
       
       if(findA(s_0) > 0 && findA(s_0) - S  <= idx1){
           return 1;
       }
       else if(findC(s_0) > 0 && findC(s_0) - S <= idx1){
           return 2;
       }
       else if(findG(s_0) > 0 && findG(s_0) - S <= idx1){
           return 3;
       }
       else{
           return 4;
       }

}

struct Results {
  int * A;
  int M; // Length of the array
};

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
        
    int N = strlen(S);
    int *impact;
    impact = malloc(sizeof(int)*M);
    
    int Min = find_min(S,0, N-1);
    
    
    for(int i = 0; i < M; i++){
      
      if(P[i] == Q[i]){
          impact[i] = VAL(S[P[i]]);
      }    
      else if(P[i] == 0 && Q[i] == N-1){
          impact[i] = Min;
      }
      else{
          impact[i] = find_min(S, P[i], Q[i]);
      }
    }
    
    result.A = impact;
    result.M = M;
    return result;
}


int main(void) {
    
    int M = 3;
    int P[] = {2,5,0};
    int Q[] = {4,5,6};
    
    char *S = "CAGCCTA";
    
    struct Results result;
    result = solution(S, P , Q, M);
    
    for(int i = 0; i < result.M; i++){
            printf("%d ",result.A[i]);
    }
    return 0;
}

