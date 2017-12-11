#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "Counter_Mutex.h"

int PTHREAD_NUM, MAX;

void *add_looper(void *c){
	int i;
	for(i = 0; i < MAX; ++i){
		counter_increment((counter_t*)c);
	}
	// for(i = 0; i < MAX; ++i){
	// 	counter_decrement((counter_t*)c);
	// }
	return NULL;
}

int main(int argc, char *argv[])
{
	freopen("Counter_Mutex_Test.txt","w",stdout);
	int i;
	counter_t counter;
	double time_used;
	struct timeval begin, end;

	for(MAX=1000;MAX<=1000000;MAX*=10){
		printf("Number: %d\n",MAX);
		for(PTHREAD_NUM=1;PTHREAD_NUM<=20;PTHREAD_NUM++){
			pthread_t threads[PTHREAD_NUM];

			counter_init(&counter, 0);
			//printf("Test of myCounter_MutexLock processing...\n");
			gettimeofday(&begin, NULL);
			for(i = 0; i < PTHREAD_NUM; ++i){
				pthread_create(&threads[i], NULL, add_looper, &counter);
			}
			for(i = PTHREAD_NUM-1; i>=0; --i){
				pthread_join(threads[i],NULL);
			}
			gettimeofday(&end, NULL);
			time_used = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
			//printf("Operation over. %.3f Sec in total.\n", time_used / 1000000);
			printf("%.3f\t", time_used / 1000000);
		}
		printf("\n");
	}
	return 0;
}
