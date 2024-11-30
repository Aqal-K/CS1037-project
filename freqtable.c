/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* modified nov 29
*
* Description:
* Function implementations for the freqtable.h header file
*
* Dependencies:
* - freqtable.h
* - pqueue.c
* - stdio.h
*/

#include "freqtable.h"
#include <stdio.h>
#define ASCII_SIZE 128

pqueue *create_table(char *inputfile) {
    FILE *readfile = fopen(inputfile,"r");

    if (readfile == NULL) {
        printf("Error: Could not find file\n");
        return NULL;
    }

    // initialize array for every ascii code and set to one
    int frequency_array[ASCII_SIZE] = {0};
    int ch;

    // iterate through file and increase frequency of each ascii index found
    while ((ch = fgetc(readfile)) != EOF) {
        if (ch >= 0 && ch < ASCII_SIZE) {
            frequency_array[ch] += 1;
        }
    }
    fclose(readfile);

    // create queue and tree nodes than enqueue frequency table entries
    pqueue *freq_table = create_queue();
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequency_array[i] != 0) {
            node_t *tree = create_treenode(i,frequency_array[i]);
            enqueue(freq_table,tree);
        }
    }
    if (freq_table->front == NULL) {
        printf("Error: Could not add values to table\n");
        free_queue(&freq_table);
        return NULL;
    }

    node_t *fileend = create_treenode(-2,1);
    enqueue(freq_table,fileend);
    return freq_table;
}
