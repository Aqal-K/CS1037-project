/**
 * Author:          Mekail Mujtaba
 * Student ID:      251372808
 * Last modified:   Nov 29th
 *
 * Description:
 * Writes encoded data to a .huf file
 *
 * Dependencies:
 * - pqueue.h
 * - stdio.h
 * - cstdint
 * - huffman_tree.h
 * - writehuf.h
 */

//gcc encode_testing.c encode.c pqueue.c decode.c writehuf.c huffman_tree.c freqtable.c

#include "pqueue.h"
#include "huffman_tree.h"
#include "writehuf.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void write_huf_file (char *input_filename, char *output_filename, node_t *huffman_tree) {
    char *code_table[ASCII_SIZE+1] = {0};
    char code[ASCII_SIZE+1];

    //Builds the code table 
    build_code_table(huffman_tree, code, 0, code_table);

    //Write metadata to output file.
    //1 Byte for # of unique characters
    //1 byte for each character, 4 bytes for each frequency
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("\nFailed to open output file!\n");
        return;
    }

    //Finds and w
    int unique_chars = count_leafnodes(huffman_tree);
    fwrite(&unique_chars, sizeof(uint8_t), 1, output_file);

    // Put different logic here for a traversal to leaf node and then writing to file
    write_queue_data(huffman_tree,output_file);

    //Opens file to read from
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {  //If ouput file fails to open
        printf("\nFailed to open input file!\n");
        fclose(output_file);
        free_tree(&huffman_tree);
    }

    //Creating buffer, counter, and character variables
    uint8_t buffer = 0;     //One buffer (8 bits) written at a time
    int bit_counter = 0;    //Counts until buffer is full
    char character;          //Stores each character from the file

    //Gets each character from the input file
    while ((character = fgetc(input_file)) != EOF) {
        if(code_table[character]) { //Makes sure character has huffman code--skips non-ascii symbols!
            for (int i = 0; code_table[character][i] != 0; i++) {
                
                buffer = (buffer << 1) | (code_table[character][i] == '1');
                bit_counter++;
                //printf("%d, ", buffer);

                //Writes the buffer to the file once it has 8 bytes
                if (bit_counter == BYTE) {
                    fwrite(&buffer, sizeof(uint8_t), 1, output_file);
                    buffer = 0;
                    bit_counter = 0; //Reset counter
                    //printf
                }
            }
        } else printf("Something went wrong with the Huffman tree--this character does not have a code!");
    }

    // Write the EOF (128) Character
    for (int i = 0; code_table[128][i] != 0; i++) {

        buffer = (buffer << 1) | (code_table[128][i] == '1');
        bit_counter++;
        //printf("%d, ", buffer);

        //Writes the buffer to the file once it has 8 bytes
        if (bit_counter == BYTE) {
            fwrite(&buffer, sizeof(uint8_t), 1, output_file);
            buffer = 0;
            bit_counter = 0; //Reset counter
            //printf
        }
    }

    //Writes remaining bits in the buffer to the file
    if (bit_counter > 0) {
        buffer <<= (BYTE - bit_counter);
        fwrite(&buffer, sizeof(uint8_t), 1, output_file);
    }

    //Clean up, clean up, everybody clean up
    //Clean up, clean up, everybody do your share!
    //(Just closes and frees everything)
    fclose(input_file);
    fclose(output_file);
    for (int i = 0; i < ASCII_SIZE+1; i++) {
        if (code_table[i]) {
            free(code_table[i]);
        }
    }

}

void build_code_table(node_t *root, char *code, int depth, char **code_table) {
    if (root == NULL) return;

    //If this is a leaf node, save the code directly
    if (root->index != -1) {
        code[depth] = '\0';
        code_table[root->index] = strdup(code); //strdup allocates and copies string. Useful when 
                                                //required memory is not the same for each code,
                                                //as is the case for a huffman tree.
        return;
    }

    //Recursively go through left and right subtrees
    code[depth] = '0';
    build_code_table(root->left, code, depth +1, code_table);
    code[depth] = '1';
    build_code_table(root->right, code, depth +1, code_table);
}

void write_queue_data(node_t *root, FILE *output_file) {
    if (root == NULL) {
        return;
    }

    write_queue_data(root->left,output_file);
    write_queue_data(root->right,output_file);

    if (root->left == NULL && root->right == NULL) {
        //Write the character to the file (1 byte)
        fputc(root->index, output_file);

        uint32_t frequency = root->weight;
        fwrite(&frequency, sizeof(uint32_t), 1, output_file); //Write frequency to the file (4 bytes)
    }
}