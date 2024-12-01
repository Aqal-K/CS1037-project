/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* last modified nov 29st
*
* Description:
* testing functions in decode.c
* Dependencies:
*  - decode.h
*/

#include <stdio.h>

#include "decode.h"

int main() {

    // Testing byte-to-bit function
    unsigned char testbyte = 92;
    int test_bits[8];
    byte_to_bit(testbyte,test_bits);

    for (int i = 0; i < 8; i++) {
        printf("bit %d: %d\n", i,test_bits[i]);
    }
    return 0;
}
