/**
* Author: Aqalmal Khalil
* Student ID: 251215993
*
* Description:
* Function implementations for the pqueue.h header file
* currently untested
* Dependencies:
* - pqueue.h
* - stdio.h
* - stdlib.h
*/
#include <pqueue.h>
#include <stdio.h>
#include "stdlib.h"

pqueue* create_queue() {
    // Create empty queue struct and initialize all variables appropriately
    pqueue *q = (pqueue*)malloc(sizeof(pqueue));
    if (q == NULL) {
        // Print message and return NULL if there is a allocation failure
        printf("create_queue error: Memory Allocation failure!\n");
        return NULL;
    }
    q->front = NULL;
    q->size = 0;
    return q;
}

void enqueue(pqueue *queue,node_t *tnode) {
    // create queue node with the same data as tnode arg
    node_q *pnode = (node_q*)malloc(sizeof(node_q));
    if (pnode == NULL) {
        // Print message and return if there is a allocation failure
        printf("enqueue error: Memory Allocation failure!\n");
        return;
    }
    pnode->next = NULL;
    pnode->data = tnode;

    //enqueue node at front will queue is empty or weight is the lowest
    if (queue->front == NULL || tnode->weight < queue->front->data->weight) {
        pnode->next = queue->front;
        queue->front = pnode;
        queue->size += 1;
    }
    else {
        // traverse queue until the weight of the current position is >= the weight of the inserting node
        node_q *current = queue->front;
        while (current->next != NULL && tnode->weight > current->data->weight) {
            current = current->next;
        }
        // enqueue the node at this correct increasing weight position
        pnode->next = current->next;
        current->next = pnode;
        queue->size += 1;
    }
}

node_t* dequeue(pqueue *queue) {
    if (queue->front == NULL) { // do nothing if queue is empty
        return NULL;
    }
    // remove front node from queue and return the tree node
    node_q *tmp = queue->front;
    node_t *treenode = queue->front->data;
    queue->front = queue->front->next;
    free(tmp);
    queue->size -= 1;
    return treenode;
}


