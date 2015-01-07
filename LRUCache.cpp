/* Implement LRU Cache 
 * - Given total possible page numbers that can be referred & cache size (
 *    total number of page frames that cache can hold at a time) 
 * - LRU cacheing scheme is to remove the least recently used frame when
 *      the cache is full & a new page is referenced which is not in cache
 * - Two data structures to use: 
 *      Queue (implemented using a doubly-linked list) - max size of Queue is   
 *          equal to the total number of frames available (cache size)
 *      Hash - page number as key & address of corresponding queue node as value
*/

#include <stdio.h>
#include <stdlib.h>

// A Queue Node 
typedef struct QNode {
    struct QNode *prev, *next;
    unsigned pageNumber;  // The page number stored in this QNode
} QNode;

// A Queue - FIFO collection of Queue Nodes
typedef struct Queue {
    unsigned count; // Number of filled frames
    unsigned numberOfFrames; // total number of frames
    QNode *front, *rear;
} Queue;


// A hash (collection of pointers to Queue Nodes)
typedef struct Hash {
    int capacity; // how many pages can be there
    QNode* *array; // an array of queue Nodes
} Hash;

// Utility function to create a new Queue Node - stores the given 'pageNumber'
QNode* newQNode(unsigned pageNumber) {
    // Allocate memory and assign 'pageNumber'
    QNode* temp = (QNode *)malloc(sizeof(QNode));
    temp->pageNumber = pageNumber;
    
    // Initialize prev and next as NULL
    temp->prev = temp->next = NULL;
    
    return temp;
}

// A utility function to create an empty Hash of given capacity
Hash* createHash (int capacity) {
    // Allocate memory for hash
    Hash* hash = (Hash *)malloc(sizeof(Hash));
    
}
