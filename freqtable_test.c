/**
* Author: Aqalmal Khalil
* Student ID: 251215993
*
* Description:
* testing file for freqtable.c
*
* Dependencies:
* - freqtable.h
* - freqtable.c
* - pqueue.h
* - pqueue.c
* - stdio.h
* + All dependencies of any files included here
*/
#include "pqueue.h"
#include "freqtable.h"
#include <stdio.h>

int main() {

    //Create frequency table corresponding to filename and print the ordered table queue
    pqueue *table = create_table("medium.txt");
    printf("Print the table:\n");
    print_queue(table);

    return 0;
}
