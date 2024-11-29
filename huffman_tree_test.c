/**
 * Author: Joshua Lee
 * Student ID: 251240670
 *
 * Description:
 * Testing file for huffman_tree.c
 *
 * Dependencies:
 * - huffman_tree.h
 * - pqueue.h
 * - stdio.h
 * - stdlib.h
 */

#include "huffman_tree.h"
#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to print the Huffman tree (inorder traversal)
void print_huffman_tree(node_t *root) {
    if (root == NULL) return;

    // Traversing the left subtree
    print_huffman_tree(root->left);

    // Printing the node (if it's a leaf, it will have a valid character)
    if (root->index != -1)
        printf("Character: %c, Frequency: %d\n", root->index, root->weight);
    else
        printf("Internal Node, Frequency: %d\n", root->weight);

    // Traversing the right subtree
    print_huffman_tree(root->right);
}

int main() {

    // Creating a frequency queue (manually or using create_table())
    pqueue *freq_queue = create_queue();
    enqueue(freq_queue, create_treenode('A', 5));
    enqueue(freq_queue, create_treenode('B', 7));
    enqueue(freq_queue, create_treenode('C', 10));
    enqueue(freq_queue, create_treenode('D', 15));
    enqueue(freq_queue, create_treenode('E', 20));
    enqueue(freq_queue, create_treenode('F', 45));

    // Building the Huffman tree
    node_t *huffman_tree = build_huffman_tree(freq_queue);

    // Printing the Huffman tree to verify
    printf("Huffman Tree (Inorder Traversal):\n");
    print_huffman_tree(huffman_tree);

    // Freeing the Huffman tree
    free_queue(&freq_queue);
    free(huffman_tree);
    return 0;
}
