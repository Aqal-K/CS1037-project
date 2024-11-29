/**
 * Author: Joshua Lee
 * Student ID: 251240670
 * modified nov 29
 * Description:
 * Implementation of a Huffman tree creation function
 * Dependencies:
 * - pqueue.h
 * - stdio.h
 * - stdlib.h
 */

#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

void free_tree(node_t **root) {
    if ((*root) == NULL) {
        return;
    }
    // traverse through the end of left and right nodes
    free_tree(&(*root)->left);
    free_tree(&(*root)->right);

    // free the current node
    free(*root);
    *root = NULL;
}

node_t* build_huffman_tree(pqueue *freq_queue) {

    // Checking if the priority queue is valid
    if (freq_queue == NULL || freq_queue->front == NULL) {
        printf("Error: Invalid or empty priority queue.\n");
        return NULL;
    }

    // Looping until there's only one node left in the queue
    while (freq_queue->size > 1) {

        // Dequeuing the two nodes with the lowest frequencies
        node_t *left = dequeue(freq_queue);
        node_t *right = dequeue(freq_queue);


    // Creating a new internal node with a combined frequency
    node_t *parent = (node_t*)malloc(sizeof(node_t));

    // Returning NULL for if in the case the memory allocation fails
    if (parent == NULL) {
        printf("Error: Memory allocation for parent node failed.\n");
        return NULL;
        }

    // Setting the parent node's properties
    parent->index = -1;
    parent->weight = left->weight + right->weight;
    parent->left = left;
    parent->right = right;

    // Enqueue the new parent node back into the priority queue
    enqueue(freq_queue, parent);
    }

    // Returning the root of the Huffman tree (aka the last node in the queue)
    return dequeue(freq_queue);
}

int count_leafnodes(node_t *root) {
    // if node is empty return zero
    if (root == NULL) {
        return 0;
    }

    // if node is not leaf node recurrsion into left and right child
    if (root->index == -1) {
        return count_leafnodes(root->left) + count_leafnodes(root->right);
    }

    // return 1 if root is leaf node
    return 1;
}
