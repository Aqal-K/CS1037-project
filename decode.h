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
 * take a byte and store each of its bits in an int array
 * @param byte byte to convert
 * @param bits int array that the bits will be stored in
 */
void byte_to_bit(unsigned char byte, int bits[8]);



#endif //DECODE_H
