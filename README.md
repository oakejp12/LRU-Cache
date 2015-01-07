lruCache
========

C Implementation of an LRU Cache 
Upcoming: C++ Implementation using freelists with Queue and Hash data structures


Build Instructions: 
========
C Source File - LRUCache.c 
     
    
How it works:
========

I used an unordered map, which enables constant time look up based on data, and a doubly linked list to implement/structure the LRU cache. I used the unordered map to store the pairs (Key, Data) and used the doubly linked list to index the pairs in the order of data time. Of course there is the need for extra memory to update and maintain the hash map and to implement the doubly linked list structure. Even though we have prev and next pointers that facilitate us to traverse the doubly linked list, keeping these two additional pointers will ensure we don't have to traverse from the front all the way to the rear whenever a node from rear needs to be removed. In simple words, keeping them makes us able to do insertions and deletions in O(1), as compared to O(n) when we have to traverse all the way front front till the rear end in order to remove the least recently used page.

Query a data with key K by the get(K) function. If that data is present in the cache, then it will return the data. Since we are using the LRU cache, we wish to update the list by moving the item of a selected data T to the front of the list. We want to keep the least recently used data on the back and the most recently used data on the front. If that data is not present, we need to insert the data and key into the list - requires that we push each element up towards the tail of the list so with n elements this will require Theta(n) time. When the cache isn't full, we place into the unordered map and add that item to the front of the list. If the cache is used up, retrieve the tail of the list, update it, then place it at the head of the list. 

