#ifndef COUNTER_SPINLOCK_H_INCLUDED
#define COUNTER_SPINLOCK_H_INCLUDED

#include "spinlock.h"

typedef struct __counter_t{
	int 		value;
	spinlock_t 	lock;
}counter_t ;

void counter_init(counter_t*, int);
int  counter_get_value(counter_t*);
void counter_increment(counter_t*);
void counter_decrement(counter_t*);


#endif // COUNTER_SPINLOCK_H_INCLUDED