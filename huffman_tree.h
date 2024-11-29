/**
 * Author: Joshua Lee
 * Student ID: 251240670
 *
 * Description:
 * Header file to define the function involved in making the Huffman Tree
 * Dependencies:
 * pqueue.h
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



#endif //HUFFMAN_TREE_H
