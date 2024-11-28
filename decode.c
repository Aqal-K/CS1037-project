/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* last modified nov 28st
*
* Description:
* Function implementations for decode.h header file
* Dependencies:
* - decode.h
* - stdio.h
* - stdlib.h
*
*/
#include <decode.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_tree(node_t **root) {
    if ((*root) == NULL) {
        return;
    }
    // traverse through the end of left and right nodes
    free_tree(&(*root)->left);
    free_tree(&(*root)->right);

    // free the current node
    free(*root);
    *root = NULL;
}
void decode(char *inputname, char *outputname) {

    // open up huff file
    FILE *huf = fopen(strncat(inputname,".huf",4),"rb");

    // error handling
    if (huf == NULL) {
        printf("Error: Can't open huf file");
        return;
    }

    // start by reconstructing tree
    // read first byte to get the number of unqiue characters to put into queue
    int unique_chars ;
    fread(&unique_chars,sizeof(int),1,huf);

    // loop to read 1 byte for the character, then 4 bytes for the frequency
    pqueue *freq_table = create_queue();
    for (int i =0; i <unique_chars; i++) {
        // Create variables to store data read by binary
        char index;
        int weight;

        // read binary from files and store in variables
        fread(&index,sizeof(char),1,huf);
        fread(&weight,sizeof(int),1,huf);

        //Create node from read binary and enqueues
        node_t *tmp = create_treenode(index,weight);
        enqueue(freq_table,tmp);
    }

    node_t *root;

    //root = create_hufftree(freq_table);

    FILE *txt = fopen(strncat(inputname,".txt",4),"r");

    unsigned char byte_reading;
    while (fread(&byte_reading,1,1,huf) == 1) {

        int *bit_array = byte_to_bit(byte_reading);
        node_t *current = root;
        for (int i = 0; i < 8; i++) {
            if (bit_array[i] == 0) {
                current = current->left;
            }
        }
    }


}
