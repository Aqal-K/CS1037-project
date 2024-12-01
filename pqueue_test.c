/**
* Author: Aqalmal Khalil
* Student ID: 251215993
*
* Description:
* Testing file for pqueue.c
*
* Dependances:
* - pqueue.h
* - pqueue.c
* - stdio.h
* - stdlib.h
* + All dependencies of any files included here
*/
#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

    //create tree nodes
    node_t *test1 = create_treenode(97,6);
    node_t *test2 = create_treenode(98,4);
    node_t *test3 = create_treenode(99,2);
    node_t *test4 = create_treenode(100,1);
    node_t *test5 = create_treenode(101,10);

    //create the priority queue
    pqueue *huffqueue = create_queue();

    // testing enqueue
    enqueue(huffqueue,test1);
    enqueue(huffqueue,test2);
    enqueue(huffqueue,test3);
    enqueue(huffqueue,test4);
    enqueue(huffqueue,test5);
    print_queue(huffqueue);

    // testing dequeue
    dequeue(huffqueue);
    print_queue(huffqueue);

    dequeue(huffqueue);
    print_queue(huffqueue);

    dequeue(huffqueue);
    print_queue(huffqueue);

    dequeue(huffqueue);
    print_queue(huffqueue);

    dequeue(huffqueue);
    print_queue(huffqueue);

    dequeue(huffqueue);
    dequeue(huffqueue);

    //test the freeing of a full queue
    enqueue(huffqueue,test1);
    enqueue(huffqueue,test2);
    enqueue(huffqueue,test3);
    enqueue(huffqueue,test4);
    enqueue(huffqueue,test5);
    print_queue(huffqueue);
    free_queue(&huffqueue);
    printf("%p",huffqueue);


    return 0;
}