# Circular Character Buffer


#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define DEBUG 1

#define dbg_print(text,arg1,arg2,myqueue) ({ \
	if(DEBUG) \
	{ \
		printf("DEBUG :"); \
		printf(#text,arg1,arg2); \
		printf("\n"); \
		printf("buffer = %s\n",myqueue->buff); \
		printf("head = %d, tail = %d\n", myqueue->head, myqueue->tail); \
	} \
})

/*
maxsize  = 12;
        a b c d e f g  h j k l  m
        0 1 2 3 4 5 6  7 8 9 10 11
empty              t,h
            t          h
          h            t
full                h  t
full    t                      h
*/

typedef struct queue
{
    char *buff;
    int  maxsize;
    int head;
    int tail;
} queue;

int q_init(queue *myqueue, int size);
int q_put(queue *myqueue, const char *data, int size);
int q_get(queue *myqueue, char *data, int size);

static bool q_full(queue *myqueue)
{
    if((myqueue->head + 1) % myqueue->maxsize == myqueue->tail)
        return true;

    return false;
}

static bool q_empty(queue *myqueue)
{
    if(myqueue->head == myqueue->tail)
        return true;
    return false;
}

static int q_size(queue *myqueue)
{
    if(myqueue->head >= myqueue->tail)
         return myqueue->maxsize - myqueue->head + myqueue->tail;
    else
         return myqueue->tail - myqueue->head;
}

int main(void) {

    queue myqueue;
    assert(q_init(&myqueue,10)==0);

    const char *data = "abcdefghjk";

    assert(q_put(&myqueue, data, 7) == 7); // abcdefg___

    char getbuff[10];
    assert(q_get(&myqueue, getbuff, 3 ) == 3); // ___defg___
    printf("getbuff = %s\n",getbuff);

    assert(q_put(&myqueue, data,5) == 5); // decdefgabc
    // full
    assert(q_full(&myqueue) == true);

    assert(q_get(&myqueue, getbuff, 9) == 9); // _e_______
    printf("getbuff = %s\n", getbuff);
    assert(q_empty(&myqueue) == true);

    return 0;
}

int q_init(queue *myqueue, int size)
{
    assert(myqueue);
    if(size == 0)
        return -1;
    char *buff = (char *) malloc(sizeof(char) * size);
    myqueue->buff = buff;
    myqueue->head = 0;
    myqueue->tail = 0;
    myqueue->maxsize = size;
    dbg_print("q_init : %s %s","","",myqueue);
    return 0;
}

int q_put(queue *myqueue, const char *data, int size)
{
    assert(myqueue);
    assert(data);

    if(!q_full(myqueue))
    {
        int currsize = q_size(myqueue);
        int wrsize = (currsize < size) ? currsize : size;
        if(myqueue->head +  wrsize < myqueue->maxsize) // no wrap around
        {
            memcpy(myqueue->buff + myqueue->head , data, wrsize);
        }
        else // wrap around the buffer
        {
            int chunk0 = myqueue->maxsize - myqueue->head;
            memcpy(myqueue->buff + myqueue->head , data, chunk0);
            memcpy(myqueue->buff, data + chunk0, wrsize - chunk0);
        }

        myqueue->head = (myqueue->head + wrsize) % myqueue->maxsize;

        dbg_print("q_put : %s, %d",data,size,myqueue);

        return wrsize;
    }

    return 0;

}

int q_get(queue *myqueue, char *data, int size)
{
    assert(myqueue);
    assert(data);

    if(!q_empty(myqueue))
    {
        int getsize = myqueue->maxsize - q_size(myqueue);
        int rdsize = (getsize < size) ? getsize : size;
        if(myqueue->tail + rdsize < myqueue->maxsize) //no wrap around
        {
            memcpy(data,myqueue->buff + myqueue->tail, rdsize);
        }
        else //wrap around
        {
            int chunk0 = myqueue->maxsize - myqueue->tail;
            memcpy(data,myqueue->buff + myqueue->tail, chunk0);
            memcpy(data+chunk0,myqueue->buff, rdsize-chunk0);
        }

        *(data + rdsize) = '\0';
        myqueue->tail = (myqueue->tail + rdsize) % myqueue->maxsize;
        dbg_print("q_get : %s, %d","", size, myqueue);
        return rdsize;
    }

    return 0;

}

