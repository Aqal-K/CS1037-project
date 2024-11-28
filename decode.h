/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* last modified nov 28st
*
* Description:
* Function definitions related to decoding
* Dependencies:
* - decode.h
*
*/
#ifndef DECODE_H
#define DECODE_H

#include <pqueue.h>

/**
 * Free a tree from the memory via post order recurrsion
 * @param root root of tree to be freed
 */
void free_tree(node_t **root);

/**
 * Decompress the binary huffman file to a text file
 * @param inputfile huffman file (.huf) to decode
 * @param outputfile name of output file (.txt) to output the decompressed text to
 */
void decode(char *inputname, char *outputname);

/**
 *
 * @param byte the byte to convert
 * @return int array containing 0 or 1 in each index
 */
int *byte_to_bit(unsigned char byte);



#endif //DECODE_H
