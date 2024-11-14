## Program high level overview #

### High level breakdown of steps/ functions required to be implemented for the program

### initialize() function
- no input parameters
- Probably for initializing the Huffman tree to be used?

### free_memory() function
- free up the memory of the nodes?
- note: might get rid of this in the huffman.c file, it doesn't even have any input parameters for what should be freed
- might need a different free function for queue vs the huffman tree

### encode() function
- parameter 1: char pointer to filename of input file
- parameter 2: char pointer to filename for output of compressed encoded file
- might want to output the encoding/decoding table formed from the tree

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

#### step 3: Make the encoding table and output encoded binary string to output file 
- open up a .huf file to bitwise write to (filename taken from parameter 2 of the encode function)
- read character by character through the text file
- for each character traverse through the tree to the corresponding leaf of the same character
- binary code for the encoded file is formed by appending 0 when the left branch is taken, and 1 for right branch
- repeat until the leaf of the current character is reached and repeat from the root for the next character
- Close the file and end the encode function.
- Note: other option to do it that I've seen online instead of traversing through the tree every time
  - traverse huffman tree once for each character in the tree to get it's respective binary huffman code. 
  - make a conversion table list to store each character and their corresponding huffman code from the tree
  - Then traverse through your input file and replace each character with their corresponding huffman code
  

- Have to free up any dynamic memory we won't be using in the decode() function
- probably just freeing up the priority queue at the end as we'll likely need huffman tree in decode 
- depending on how the encoding/decoding table implemented might need to free it up here as well

### decode() function
- parameter 1: input .huf file
- parameter 2: output .txt file
- maybe put another parameter for the encoding decoding table to be used or for the huffman tree

#### step 1: convert the .huf file to the .txt output using the encoding table
- Open up the .huf file to binary read
- use the encoded file to traverse through the huffman tree (left for 0,right for 1)
- once a leaf character is reached print the corresponding character into the output .txt file
- go back to the root of the huffman tree and repeat the process until the end of the .huf file is reached
- close the .huf and .txt file
- Might free up memory of the nodes at this point using a free memory function?

