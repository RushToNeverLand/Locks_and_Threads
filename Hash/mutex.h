#ifndef MUTEX_H_INCLUDED
#define MUTEX_H_INCLUDED

typedef struct __mutex_t {
	int flag;
} mutex_t;

void mutex_init(mutex_t *lock);
void mutex_acquire(mutex_t *lock);
void mutex_release(mutex_t *lock);

#endif