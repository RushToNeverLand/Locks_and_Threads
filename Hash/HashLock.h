#ifndef HASHLOCK_H_INCLUDED
#define HASHLOCK_H_INCLUDED

#include <pthread.h>
// #include "List_Spinlock.h"
// #include "List_Mutex.h"
// #include "List_TwoPhase.h"
#include "List_Pthreadlock.h"

typedef struct __hash_t{
	unsigned int Size;
	list_t 	*bucket;
}hash_t;

void hash_init(hash_t *, int);
void hash_insert(hash_t *, unsigned int);
void hash_delete(hash_t *, unsigned int);
void *hash_lookup(hash_t *, unsigned int);
void hash_free(hash_t *);

#endif 