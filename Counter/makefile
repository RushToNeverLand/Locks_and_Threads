all: libcounter.so libCounter_Mutex.so libCounter_Pthread.so libCounter_TwoPhase.so Counter_Spinlock_Test Counter_Mutex_Test Counter_Pthread_Test Counter_TwoPhase_Test
libcounter.so: Counter_Spinlock.c Counter_Spinlock.h spinlock.c spinlock.h xchg.c
	@gcc -shared -fPIC -o libcounter.so Counter_Spinlock.c Counter_Spinlock.h spinlock.c spinlock.h xchg.c
libCounter_Mutex.so: Counter_Mutex.c mutex.c Counter_Mutex.h mutex.h xchg.c sys_futex.c
	@gcc -shared -fPIC -o libCounter_Mutex.so Counter_Mutex.c mutex.c Counter_Mutex.h mutex.h xchg.c sys_futex.c
libCounter_Pthread.so: Counter_Pthread.c Counter_Pthread.h
	@gcc -shared -fPIC -o libCounter_Pthread.so Counter_Pthread.c Counter_Pthread.h
libCounter_TwoPhase.so: Counter_TwoPhase.c Counter_TwoPhase.h two_phase.c two_phase.h xchg.c sys_futex.c
	@gcc -shared -fPIC -o libCounter_TwoPhase.so Counter_TwoPhase.c Counter_TwoPhase.h two_phase.c two_phase.h xchg.c sys_futex.c

Counter_Spinlock_Test: Counter_Spinlock_Test.c
	@gcc -o Counter_Spinlock_Test Counter_Spinlock_Test.c -lpthread -L. -lcounter -Wall -std=gnu99
Counter_Mutex_Test: Counter_Spinlock_Test.c
	@gcc -o Counter_Mutex_Test Counter_Mutex_Test.c -lpthread -L. -lCounter_Mutex -Wall -std=gnu99
Counter_Pthread_Test: Counter_Pthread_Test.c
	@gcc -o Counter_Pthread_Test Counter_Pthread_Test.c -lpthread -L. -lCounter_Pthread -Wall -std=gnu99
Counter_TwoPhase_Test: Counter_TwoPhase_Test.c
	@gcc -o Counter_TwoPhase_Test Counter_TwoPhase_Test.c -lpthread -L. -lCounter_TwoPhase -Wall -std=gnu99
clean:
	rm -f Counter_Spinlock_Test libCounter_Spinlock.so libCounter_Mutex.so libCounter_Pthread.so libCounter_TwoPhase.so Counter_Mutex_Test Counter_Pthread_Test Counter_TwoPhase_Test
