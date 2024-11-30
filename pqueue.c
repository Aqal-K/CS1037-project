/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* modified nov 29
* Description:
* Function implementations for the pqueue.h header file
* Dependencies:
* - pqueue.h
* - stdio.h
* - stdlib.h
*/
#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

node_t* create_treenode(int index, int weight) {

    // malloc the memory and assigning all fields before returning the node
    node_t *tree = (node_t*)malloc(sizeof(node_t));
    tree->index = index;
    tree->weight = weight;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}
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
        // traverse queue until the weight of the current position is > the weight of the inserting node
        node_q *current = queue->front;
        while (current->next != NULL && tnode->weight > current->next->data->weight) {
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
        printf("Dequeue Error: Queue is Empty\n");
        return NULL;
    }
    // remove front node from queue and return the tree node
    node_q *tmp = queue->front;
    node_t *treenode = tmp->data;
    queue->front = queue->front->next;
    free(tmp);
    tmp = NULL;
    queue->size -= 1;
    return treenode;
}

void free_queue(pqueue **queue) {
    // empty all nodes in queue then free queue
    node_q *tmp;
    while ((*queue)->front != NULL) {
        tmp = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        free(tmp->data);
        free(tmp);
    }
    free(*queue);
    *queue = NULL;
}

void print_queue(pqueue *queue) {
    if (queue == NULL) {
        printf("Empty queue, unable to print");
        return;
    }
    node_q *current = queue->front;
    while (current != NULL) { // iterate through the queue to print
        printf("%d: %d\n",current->data->index,current->data->weight);
        current = current->next;
    }
}