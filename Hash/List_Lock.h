#ifndef LIST_LOCK_H_INCLUDED
#define LIST_LOCK_H_INCLUDED

#include "spinlock.h"
// #include "mutex.h"
// #include "two_phase.h"
// #include <pthread.h>

typedef struct __node_t{
	unsigned int key;
	struct __node_t *next;
}node_t;

typedef struct __list_t{
	node_t 		*head;
	spinlock_t 	lock;
	// mutex_t lock;
	// two_phase_t lock;
	// pthread_mutex_t lock;
}list_t;

void list_init(list_t *);
void list_insert(list_t *, unsigned int);
void list_delete(list_t *, unsigned int);
void *list_lookup(list_t *, unsigned int);
void list_free(list_t *);


#endif 