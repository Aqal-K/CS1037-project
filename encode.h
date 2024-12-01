/**
 * Author: Aqalmal Khalil
 * Student ID: 251215993
 * Description:
 *  header file for Implementation of the encode() function for the Huffman compression.
 * Integrates freqtable.c, huffman_tree.c, and **INSERT STEP 3 NAME HERE**
 *
 * Dependencies:
 */

#ifndef ENCODE_H
#define ENCODE_H

/**
 * takes am input text file and encodes and compresses it into a binary .huf file
 * which can be decompressed using decode
 * @param input_filename name of the input text file ending in .txt
 * @param output_filename name of the output file ending in .huf
 */
void encode(char *input_filename, char *output_filename);

#endif //ENCODE_H
