#include <unordered_map>
#include <vector>
#include "LRUCache.h"

using namespace std;

template <class K,  class T>
Cache<K,T>::Cache(size_t size){
	entries = new construct<K, T>[size];
	
	int i = 0;
	for (i; i < size; i++) {
		_freeEntries.push_back(entries + i);
	}
	head = new construct < K, T > ;
	tail = new construct < K, T > ;
	head->prev = nullptr;
	head->next = tail;
	tail->prev = head;
	tail->next = nullptr;
}

template <class K, class T>
Cache<K, T>::~Cache(){
	delete head;
	delete tail;
	delete [] entries;
}

template <class K, class T>
void Cache<K, T>::put(K key, T data) {
	construct<K, T>* node = _mapping[key];
	if (node) {
		// Refresh the lined list
		detach(node);
		node->data = data;
		attach(node);
	}
	else {
		if (_freeEntries.empty()) {
			node = tail->prev;
			detach(node);
			_map.erase(node->key);
			node->data = data;
			node->key = key;
			_map[key] = node;
			attach(node);
		}
		else {
			node = _freeEntries.back();
			_freeEntries.pop_back();
			node->key = key;
			node->data = data;
			_map[key] = node;
			attach(node);
		}
	}

}

template <class K, class T>
T Cache<K, T>::get(K key) {
	construct<K,T>* node = _map[key];
	if (node) {
		detach(node);
		attach(node);
		return node->data;
	}
	else { return nullptr; }
}




