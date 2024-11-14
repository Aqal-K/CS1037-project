## Program high level overview #

### High level breakdown of steps/ functions required to be implemented for the program

### initialize() function

- no input parameters
- Probably for initializing the Huffman tree to be used?


### free_memory() function

- free up the memory of the nodes?
- note: might get rid of this in the huffman.c file, it doesn't even have any input parameters for what should be freed

### encode() function

- parameter 1: char pointer to filename of input file
- parameter 2: char pointer to filename for output of compressed encoded file


#### step 1: take input file and create a frequency table from all the characters
- for each char, keep counter of how many times it appears in the text file (make this as an array?)
- each entry in the freq table will be a node_t struct to contain the character and it's frequency
- Each node should enqueued in a priority queue from lowest (front of queue) to the highest frequency
  - Priority queue will have enqueue, and dequeue function.
  - create queue struct to contain node_t variable, pointer to front node_t, and pointer to next node_t  
    

#### step 2: Create a huffman Tree from the frequency table
- Dequeue the front 2 nodes and create a new node that's frequency is the sum of the 2 dequeued nodes and with a "blank" character
- Should have tree struct with node_t variable, pointers to left and right node.
- left pointer will be first node dequeued, right pointer to second dequeued node
- priority enqueue only the new node created back into the list 
- Repeat dequeue front 2 nodes and whole process until 1 node is left in the list which is the root of the huffman tree


#### step 3: Output the encoded file 
- open up a .huf file to bitwise write to (filename taken from parameter 2 of the encode function)
- read character by character through the text file
- for each character traverse through the tree to the corresponding leaf of the same character
- binary code for the encoded file is formed by appending 0 when the left branch is taken, and 1 for right branch
- repeat until the leaf of the current character is reached and repeat from the root for the next character
- Close the file and end the encode function.

