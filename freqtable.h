/**
* Author: Aqalmal Khalil
* Student ID: 251215993
* modified nov 29
* 
* Description:
* Header file to define functions invloved in creating the frquency table
* Dependencies:
* pqueue.h
*/
#ifndef FREQTABLE_H
#define FREQTABLE_H
#include "pqueue.h"

/**
 * take a .txt file and create the frequency table queue from it
 * @param inputfile filename of textfile
 * @return the priority queue representing the frequency table
 */
pqueue *create_table(char *inputfile);



#endif //FREQTABLE_H
