/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* modified nov 29
*
* Description:
* Header file to define priority queue struct and functions for the Huffman tree nodes
*
*/
#ifndef PQUEUE_H
#define PQUEUE_H

// Could move this struct to separate common.h,common.c file for common functions to be used in program
/**
 * Structure: node_t
 *
 * Purpose: represents a Huffman tree node
 *
 * Fields:
 * index (int) - ASCII character index (-1 represents a blank character)
 * weight (unsigned int) - Frequency of the character
 * left (node_t) - pointer to node's left child
 * right (node_t) - pointer to node's right child
 */
typedef struct node_t {
    int index;
    unsigned int weight;
    struct node_t *left;
    struct node_t *right;
} node_t;

/**
 * Structure: node_q
 *
 * Purpose: represents a queue node that stores the data of a huffman tree node
 *
 * Fields:
 * data (node_t) - the huffman tree node that this queue node stores
 * next (node_q) - pointer to next node in the queue
 */
typedef struct node_q {
    node_t *data;
    struct node_q *next;
} node_q;

/**
 * Structure: pqueue
 *
 * Purpose: represents a priority queue that queue nodes will be added and removed from
 *
 * Fields:
 * front (node_q) - pointer to the front queue node
 * size (int) - stores the size of the priority queue
 */
typedef struct pqueue {
    node_q *front;
    int size;
} pqueue;

/**
 * Create an empty queue with all variables properly initialized
 * @return The empty queue that is created
 */
pqueue* create_queue();

/**
 * create a huffman tree node (NOTE: this function could be moved to another file e.g a common.h common.c)
 * @param index character of tree node
 * @param weight frequency of tree node character
 * @return tree node created
 */
node_t* create_treenode(int index, int weight);

/**
 * Enqueue the tree node in the appropriate priority position by its weight
 * @param queue queue that node will be added to
 * @param tnode tree node to be added to queue
 */
void enqueue(pqueue *queue,node_t *tnode);

/**
 * Dequeue's a tree node from the queue
 * @param queue the queue to be dequeued from
 * @return the front tree node from the queue
 */
node_t* dequeue(pqueue *queue);

/**
 * Frees the memory of a queue and it's nodes
 * @param queue The pointer to queue that will be freed.
 */
void free_queue(pqueue **queue);

/**
 * print out all nodes of a queue
 * @param queue The queue to be printed
 */
void print_queue(pqueue *queue);
#endif //PQUEUE_H




