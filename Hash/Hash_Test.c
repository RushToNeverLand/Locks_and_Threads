#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "HashLock.h"

int PTHREAD_NUM, MAX;

void *op_looper(void *arg){
	int i, lu, is, de;
	lu = is = de = 0;
	srand(time(0));
	for(i = 0; i < MAX; ++i){
		int rd = rand() % 10086;
		hash_insert((hash_t*)arg, rd);
		++is;
	}
	// srand(time(0));
	// for(i = 0; i < MAX; ++i){
	// 	int rd = rand() % 10086;
	// 	hash_delete((hash_t*)arg, rd);
	// 	++is;
	// }
	return NULL;
}

int main(int argc, char *argv[])
{
	freopen("Hash_Pthread_Test.txt","w",stdout);
	int i;
	int SIZE=1024;
	hash_t hash;
	double time_used;
	struct timeval begin, end;
	for(MAX=1000;MAX<=1000000;MAX*=10){
		printf("Number: %d\n",MAX);
		for(PTHREAD_NUM=1;PTHREAD_NUM<=20;PTHREAD_NUM++){
			pthread_t threads[PTHREAD_NUM];

			hash_init(&hash, SIZE);
			//printf("Test of myHash_PthreadLock processing...\n");
			gettimeofday(&begin, NULL);
			for(i = 0; i < PTHREAD_NUM; ++i){
				pthread_create(&threads[i], NULL, op_looper, &hash);
			}
			for(i = PTHREAD_NUM-1; i>=0; i--){
				pthread_join(threads[i],NULL);
			}
			gettimeofday(&end, NULL);
			time_used = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
			hash_free(&hash);
			printf("%.3f\t", time_used / 1000000);
		}
		printf("\n");
	}
	return 0;
}