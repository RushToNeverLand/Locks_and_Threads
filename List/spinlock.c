#include "spinlock.h"

void spinlock_init(spinlock_t *lock){
	lock->flag=0;
}

//version 1.0
// void spinlock_acquire(spinlock_t *lock){
// 	while(xchg(&lock->flag,1)==1){
// 		//spin
// 	}
// }

//version 2.0 load-linked & store-conditional
int LoadLinked(int *ptr){
	return *ptr;
}

int StoreConditional(int *ptr,int value){
	if((*ptr)==0){
		*ptr=value;
		return 1;
	}
	else{
		return 0;
	}
}

void spinlock_acquire(spinlock_t *lock){
	while(LoadLinked(&lock->flag)||!StoreConditional(&lock->flag,1)){
		//spin
	}
}

void spinlock_release(spinlock_t *lock){
	lock->flag=0;
}