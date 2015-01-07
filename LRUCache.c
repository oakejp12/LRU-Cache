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
Hash* createHash(int capacity) {
    // Allocate memory for hash
    Hash* hash = (Hash *)malloc(sizeof(Hash));
    hash->capacity = capacity;
    
    // Create an array of pointers for referring Queue Nodes
    hash->array = (QNode **)malloc(hash->capacity * sizeof(QNode*));
    
    // Initialize all hash entries as empty
    int i;
    for (i=0; i < hash->capcity; ++i)
        hash->array[i] = NULL;
    
    return hash;
}

/* A function to check if there is slot available in memory
 * Since count is the number of filled frames and numberOfFrames 
 *  is the total number of frames then this should return false is memory 
 *  is available
*/
int AreAllFramesFull (Queue* queue) {
    return queue->count == queue->numberOfFrames;
}

/* Utility function to check if queue is empty
 * Since the Queue uses a FIFO method, new items are  
 *  added to the tail of the list. So if there is nothing 
 *  at the tail then the Queue is empty.
 */
int isQueueEmpty(Queue* queue) {
    return queue->rear == NULL;
}

// A utility function to delete a frame from queue
void deQueue (Queue* queue) {
    
    // If queue is empty then no need to delete
    if (isQueueEmpty(queue))
        return;
    
    // If this is the only node in list, then change front
    if (queue->front == queue->rear) 
        queue->front == NULL;
    
    if (queue->rear)
        queue->rear->next = NULL;
    
    free(temp);
    
    // decreament the number of full frames by 1
    queue->count--;
}


// A function to add a page with given 'pageNumber' to both queue
// and hash
void Enqueue(Queue* queue, Hash* hash, unsigned pageNumber) {
    
    // If all frames are full, remove the page at the rear
    if (AreAllFramesFull(queue)) {
        // remove page from hash
        hash->array[queue->rear->pageNumber] = NULL;
        deQueue(queue);
    }
    
    
    
    
    if(isQueueEmpty(queue)){
        
    }
    
}



