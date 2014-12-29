#ifndef _lrucache_h_
#define _lrucache_h_

#include <unordered_map>
#include <vector>

template<class K, class T>
struct construct {
	K key;
	T data;
	construct* prev;
	construct* next;
};

template<class K, class T>
class Cache {
private:
	std::unordered_map < K, construct<K, T>* >  _map;
	std::vector< construct<K, T>* > _freeEntries;
	construct<K, T> * head;
	construct<K, T> * tail;
	construct<K, T> * entries;

	void detach(Cache<K, T>* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	
	void attach(Cache<K, T>* node) {
		node->next = head->next;
		node->prev = head;
		head->next = node;
		node->next->prev = node;
	}
	
public:
	Cache(size_t);
	~Cache();
	void put(K, T);
	T get(K);
	void print(construct<K, T>);

};





#endif _lrucache_h_
