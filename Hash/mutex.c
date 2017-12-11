#include "sys_futex.c"
#include "mutex.h"
#include "xchg.c"

void mutex_init(mutex_t *lock){
	lock->flag=0;
}

void mutex_acquire(mutex_t *lock){
	if(xchg(&lock->flag,1)==1){//wait
		sys_futex(&lock->flag,FUTEX_WAIT,1,0,0,0);
		mutex_acquire(lock);
	}
	else{//get the critical section
		return ;
	}	
}

void mutex_release(mutex_t *lock){
	xchg(&lock->flag,0);
	sys_futex(&lock->flag,FUTEX_WAKE,1,0,0,0);
}