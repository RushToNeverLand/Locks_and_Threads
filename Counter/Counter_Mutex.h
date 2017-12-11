#ifndef COUNTER_MUTEX_H_INCLUDED
#define COUNTER_MUTEX_H_INCLUDED

#include "mutex.h"

typedef struct __counter_t{
	int 		value;
	mutex_t 	lock;
}counter_t ;

void counter_init(counter_t*, int);
int counter_get_value(counter_t*);
void counter_increment(counter_t*);
void counter_decrement(counter_t*);

#endif 