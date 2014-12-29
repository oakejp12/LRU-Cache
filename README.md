lruCache
========

Implementation of an LRU Cache 


Build Instructions: 
========
C++ - LRUCache.h - Header file
      LRUCache.cpp - Source file
      
How it works:
========

I used an unordered map and a doubly linked list to implement/structure the LRU cache. I used the unordered map to store the pairs (Key, Data) and used the doubly linked list to index the pairs in the order of data time.

Query a data with key K by the get(K) function. If that data is present in the cache, then it will return the data. Since we are using the LRU cache, we want to refresh the list by moving the item of data T to the head. We want to keep the least recently used data on the back and the most recently used data on the front. If that data is not present, we need to insert the data and key into the list. When the cache isn't full, we place into the unordered map and add that item to the front of the list. If the cache is used up, retrieve the tail of the list, update it, then place it at the head of the list. 

