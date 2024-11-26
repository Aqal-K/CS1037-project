/*
 * CS1037 Huffman Coding
 *
 * This file contains the main program,the structure of the Huffman node
 * and user interface for running your Huffman Encoder/Decoder. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr,
                "USAGE: ./huffman [encode | decode] "
                "<input file> <output file>\n");
        return 0;
    }

    if (strcmp(argv[1], "encode") == 0)
        encode(argv[2], argv[3]);
    else if (strcmp(argv[1], "decode") == 0)
        decode(argv[2], argv[3]);
    else
        fprintf(stderr,
                "USAGE: ./huffman [encode | decode] "
                "<input file> <output file>\n");
    return 0;
}



