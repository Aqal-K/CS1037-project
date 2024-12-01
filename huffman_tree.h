/**
 * Author: Joshua Lee
 * Student ID: 251240670
 *
 * Description:
 * Header file to define the function involved in making the Huffman Tree
 * Dependencies:
 * pqueue.c
 * pqueue.h
 * + All dependencies of any files included here
 */
#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include "pqueue.h"

/**
 * To construct a Huffman tree from a priority queue containing nodes representing
 *   character frequencies
 * @param freq_queue - pointer to a priority queue where each node, node_t,
 *   represents a character and its frequency
 * @return node_t* - a pointer to the root node of the Huffman tree. Returns NULL if
 *   the queue is invalid or empty
 */
node_t* build_huffman_tree(pqueue *freq_queue);


/**
 * Free a tree from the memory via post order recurrsion
 * @param root root of tree to be freed
 */
void free_tree(node_t **root);

/**
 * count the number of leaf nodes (unique characters, in the tree)
 * @param root root of huffman tree
 * @return count of the leaf nodes
 */
int count_leafnodes(node_t *root);

/**
 * print the huffman tree in order
 * @param root root of tree to print
 */
void print_huffman_tree(node_t *root);

#endif //HUFFMAN_TREE_H
