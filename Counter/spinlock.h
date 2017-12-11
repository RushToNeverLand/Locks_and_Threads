#ifndef SPINLOCK_H_INCLUDED
#define SPINLOCK_H_INCLUDED

typedef struct __spinlock_t{
	int flag;
}spinlock_t;

void spinlock_init(spinlock_t *lock);
void spinlock_release(spinlock_t *lock);
void spinlock_acquire(spinlock_t *lock);
int LoadLinked(int *);
int StoreConditional(int *,int );

#endif // SPINLOCK_H_INCLUDED