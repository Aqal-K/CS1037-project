/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* last modified nov 29st
*
* Description:
* Function definitions related to decoding
* Dependencies:
*
*/
#ifndef DECODE_H
#define DECODE_H

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
