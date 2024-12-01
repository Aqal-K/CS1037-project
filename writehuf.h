/**
 * Author:          Mekail Mujtaba
 * Student ID:      251372808
 * Last modified:   Nov 29th
 * Description:
 * Header file for functions to write encoded data to a .huf file
 * Dependencies:
 * - pqueue.h
 * - stdio.h
 */

#ifndef WRITEHUF_H
#define WRITEHUF_H

#include <stdio.h>
#include "pqueue.h"

#define ASCII_SIZE 128
#define BYTE 8

/**
 * Builds code table by traversing entire huffman tree
 *
 * @param root:         Root of Huffman tree
 * @param code:         The code for each character, built as we go along
 * @param depth:        How far into the huffman tree this call is
 * @param code_table:   Pointer to code table to build
 * 
 * Builds the code table
 */
void build_code_table(node_t *root, char *code, int depth, char **code_table);

/**
 * Writes encoded data to a .huf file
 * 
 * @param input_filename:   File name of .txt file to read from
 * @param output_filename:  File name of .huf file to create/write to
 * @param huffman_tree:     Pointer to huffman tree
 * 
 * Does not return anything, but creates a file with the encoded data
 */
void write_huf_file (char *input_filename, char *output_filename, node_t *huffman_tree);

/**
 * Writes the data of each leaf node into the .huf file for reconstructing the tree
 * @param root root of tree
 * @param output_file file to write
 */
void write_queue_data(node_t *root, FILE *output_file);

#endif //WRITEHUF_H