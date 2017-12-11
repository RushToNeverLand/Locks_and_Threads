#include <stdlib.h>
#include "HashLock.h"

void hash_init(hash_t *hash, int size){
	hash->Size = size;
	hash->bucket = (list_t *)malloc(size*sizeof(list_t));
	int i;
	for (i = 0; i < size; ++i){
		list_init(&hash->bucket[i]);
	}
}

void hash_insert(hash_t *hash, unsigned int key){
	int idx = key % (hash->Size);
	list_insert(&hash->bucket[idx], key);
}

void hash_delete(hash_t *hash, unsigned int key){
	int idx = key % (hash->Size);
	list_delete(&hash->bucket[idx], key);
}

void *hash_lookup(hash_t *hash, unsigned int key){
	int idx = key % (hash->Size);
	return list_lookup(&hash->bucket[idx], key);
}

void hash_free(hash_t *hash){
	int i, len = hash->Size;
	for (i = 0; i < len; ++i)
		list_free(&hash->bucket[i]);
}