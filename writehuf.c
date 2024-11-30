/**
 * Author:          Mekail Mujtaba
 * Student ID:      251372808
 * Last modified:   Nov 29th
 * Description:
 * Writes encoded data to a .huf file
 * Dependencies:
 * - pqueue.h
 * - stdio.h
 * - cstdint
 * - huffman_tree.h
 * - writehuf.h
 */


#include "pqueue.h"
#include "huffman_tree.h"
#include "writehuf.h"
#include <stdio.h>
#include <cstdint>

void write_huf_file (char *input_filename, char *output_filename, node_t *huffman_tree, pqueue *freq_queue) {
    char *code_table[ASCII_SIZE] = {0};
    char code[ASCII_SIZE];

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

    node_q *current = freq_queue->front;
    while (current != NULL) {
        //Write the character to the file (1 byte)
        fputc(current->data->index, output_file);

        uint32_t frequency = current->data->weight;
        fwrite(&frequency, sizeof(uint32_t), 1, output_file); //Write frequency to the file (4 bytes)

        current = current->next; //Increment to next node in queue
    }

    //Opens file to read from
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {  //If ouput file fails to open
        printf("\nFailed to open input file!\n");
        fclose(output_file);
        free_tree(&huffman_tree);
        free_queue(freq_queue);
    }

    //Creating buffer, counter, and character variables
    uint8_t buffer = 0;     //One buffer (8 bits) written at a time
    int bit_counter = 0;    //Counts until buffer is full
    int character;          //Stores each character from the file

    //Gets each character from the input file
    while ((character = fgetc(input_file)) != EOF) {
        if(code_table[character]) { //Debugging check to make sure character has a huffman code
            for (int i = 0; code_table[character][i] != 0; i++) {
                buffer = (buffer << 1) | (code_table[ch][i] = '0');
                bit_counter++;

                //Writes the buffer to the file once it has 8 bytes
                if (bit_counter == BYTE_SIZE) {
                    fwrite(&buffer, sizeof(uint8_t), 1, output_file);
                    buffer = 0;
                    bit_counter = 0; //Reser
                }
            }
        } else printf("Something went wrong with the Huffman tree--this character does not have a code!");
    }

    //Writes remaining bits in the buffer to the file
    if (bit_counter > 0) {
        buffer <<= (BYTE_SIZE - bit_counter);
        fwrite(&buffer, sizeof(uint8_t), 1, output_file);
    }

    //Clean up, clean up, everybody clean up
    //Clean up, clean up, everybody do your share!
    //(Just closes and frees everything)
    fclose(input_file);
    fclose(output_file);
    free_tree(&huffman_tree);
    free_queue(&freq_queue);
    for (int i - 0; i < ASCII_SIZE; i++) {
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
