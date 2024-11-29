/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* last modified nov 29st
*
* Description:
* Function implementations for decode.h header file
* Dependencies:
* - decode.h
* - stdio.h
* - string.h
* - huffman_tree.h
*/
#include <decode.h>
#include <stdio.h>
#include <string.h>
#include "huffman_tree.h"

void decode(char *inputname, char *outputname) {

    // open up huff file
    FILE *huf = fopen(strncat(inputname,".huf",4),"rb");

    // error handling
    if (huf == NULL) {
        printf("Error: Can't open huf file");
        return;
    }

    // start by reconstructing tree
    // read first byte to get the number of unique characters to put into queue
    int unique_chars ;
     if (fread(&unique_chars,sizeof(int),1,huf) != 1) {
         printf("error reading file: Not properly formatted");
         return;
     }

    // loop to read 1 byte for the character, then 4 bytes for the frequency
    pqueue *freq_table = create_queue();
    for (int i =0; i <unique_chars; i++) {
        // Create variables to store data read by binary
        signed char index;
        int weight;

        // read binary from files and store in variables
        fread(&index,sizeof(char),1,huf);
        fread(&weight,sizeof(int),1,huf);

        //Create node from read binary and enqueues
        node_t *tmp = create_treenode(index,weight);
        enqueue(freq_table,tmp);
    }

    node_t *root = build_huffman_tree(freq_table);

    FILE *txt = fopen(strncat(inputname,".txt",4),"w");

    unsigned char byte_reading;
    node_t *current = root;
    while (fread(&byte_reading,1,1,huf) == 1) {

        int *bit_array = byte_to_bit(byte_reading);

        // for every byte read through the 8 bits
        for (int i = 0; i < 8; i++) {

            // if we reach a leaf node write the character to the file, start back at the root
            if (current->index != -1) {
                if (current->index == -2) { // end of file reached: break out of for loop
                    break;
                }
                fputc(current->index,txt);
                current = root;
            }
            // if the current bit is zero traverse left
            else if (bit_array[i] == 0) {
                current = current->left;
            }
            // if the current bit is 1 traverse right
            else {
                current = current->right;
            }
        }
    }
    fclose(txt);
    fclose(huf);

    free_queue(&freq_table);
    freq_table = NULL;
    free_tree(&root);
    root = NULL;
}
