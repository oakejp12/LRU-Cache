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


// Utility function to create an empty Queue
// Queue can have at most 'numberOfFrames' nodes
Queue* createQueue(int numberfFrames) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    
    // The queue is empty
    queue->count = 0;
    queue->front = queue->rear = NULL;
    
    // Number of frames that can be stored in memory
    queue->numberOfFrames = numberOfFrames;
    
    return queue;
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
    
    // If all frames are full, remove the page at the rear since we are 
    // doing least recently used
    if (AreAllFramesFull(queue)) {
        // remove page from hash
        hash->array[queue->rear->pageNumber] = NULL;
        deQueue(queue);
    }
    
    // Create a new node with given page number,
    // And add the new node to the front of queue
    QNode* temp = newQNode(pagenumber);
    temp->next = queue->front;
    
    // If queue is empty, change both front and rear pointers
    if(isQueueEmpty(queue))
        queue->rear = queue->front = temp;
    else { // Else change the front
        queue->front->prev = temp;
        queue->front = temp;
    }
    
    // Add page entry to hash as well
    hash->array[pageNumber] = temp;
    
    // increment number of full frames
    queue->count++;
}

/*
 * This function is called when a page with given 'pageNumber' is referenced
 *  from cache (or memory). There are two cases:
 * 1. Frame is not there in memory, we bring it in memory and add to the front of the queue
 * 2. Frame is there in memory, we move the frame to the front of queue
*/
void ReferencePage(Queue* queue, Hash* hash, unsigned pageNumber) {
    
    QNode* reqPage = hash->array[pageNumber];
    
    // the page is not in cache, bring it
    if (reqPage == NULL)
        Enqueue(queue,hash,pageNumber);
    else if (reqPage != queue->front) { // Page is present but not at front, change pointer
        
        // Unlink requested page from its current location in queue
        reqPage->prev->next = reqPage->next;
        if (reqPage -> next)
            reqPage->next->prev = reqPage->prev;
        
        // If the requested page is rear, then change rear
        // as this node will be move to front
        if (reqPage == queue->rear){
            queue->rear = reqPage->prev;
            queue->rear->next = NULL;
        }
        
        // Put the requested page before current front
        reqPage->next = queue->front;
        reqPage->prev = NULL;
        
        // Change prev of current front
        reqPage->next->prev = reqPage;
        
        // Change front to requested page
        queue->front = reqPage;
    }
}


// Driver program to test above functions
int main() {
    
    // Let cache hold 4 page
    Queue* q = createQueue(4);
    
    // Let 10 different pages be requested
    // PAges to be referenced are number from 0 to 9
    Hash* hash = createHash(10);
    
    ReferencePage(q, hash, 1);
    ReferencePage(q, hash, 2);
    ReferencePage(q, hash, 3);
    ReferencePage(q, hash, 1);
    ReferencePage(q, hash, 4);
    ReferencePage(q, hash, 5);
    
    // Let us print cache frames after the above referenced pages
    printf("%d ", q->front->pageNumber);
    printf("%d ", q->front->next->pageNumber);
    printf("%d ", q->front->next->next->pageNumber);
    printf("%d ", q->front->next->next->next->pageNumber);
    
    
}






