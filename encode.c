/**
 * Author: Joshua Lee
 * Description:
 * Implementation of the encode() function for the Huffman compression.
 * Integrates freqtable.c, huffman_tree.c, and **INSERT STEP 3 NAME HERE**
 *
 * Dependencies:
 * - freqtable.h
 * - pqueue.h
 * - huffman_tree.h
 * - stdio.h
 * - stdlib.h
 */

#include "freqtable.h"
#include "pqueue.h"
#include "huffman_tree.h"
#include <stdio.h>

void encode(char *input_filename, char *output_filename) {

    // Step 1: Create a frequency table from the input file by using create_table() from freqtable.c
    pqueue *freq_queue = create_table(input_filename);

    // Checking if the frequency table was created successfully
    if (freq_queue == NULL) {
        printf("Error: Failed to create frequency table.\n");
        return;
    }

    // Step 2: Build the Huffman tree from the frequency table by using build_huffman_tree() from huffman_tree.c
    node_t *huffman_tree = build_huffman_tree(freq_queue);

    // Checking if the Huffman tree was created successfully
    if (huffman_tree == NULL) {
        printf("Error: Failed to build Huffman tree.\n");
        free_queue(&freq_queue);
        return;
    }

    // Space reserved for Step 3

    printf("Encoding functionality is incomplete. Step 3 not implemented yet.\n");

    // Cleanup; Freeing dynamically allocated memory
    free_tree(&huffman_tree);
    free_queue(&freq_queue);
}
