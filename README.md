lruCache
========

Implementation of an LRU Cache 


Build Instructions: 
C++ - LRUCache.h - Header file
      LRUCache.cpp - Source file
      
I used a hash map (unordered map) and a doubly linked list to implement/structure the LRU cache. I used the hash map to store the pairs (Key, Data) and used the doubly linked list to index the pairs in the order of data time. Once a data with key K is queried, the get(K) is first called. If the data of the key K is in the cache, the cache just returns the data and refreshes the data in the linked list. To refresh the data T in the list, we move the item of data T to the head of the list - We want to keep the least recently used data on the back and the most recently used pages on front. Otherwise, if the data T of key K is not in the cache, we need to insert the pair into the list. If the cache is not full, we insert into the hash map, and add the item at the head of the list. If the cache is already full, we get the tail of the list and update it, then move this item to the head of the list. 
