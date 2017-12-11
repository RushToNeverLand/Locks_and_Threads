all: libhash.so hash_test
libhash.so: HashLock.c HashLock.h List_Pthreadlock.h  List_Pthreadlock.c
	@gcc -shared -fPIC -o libhash.so HashLock.c HashLock.h List_Pthreadlock.h  List_Pthreadlock.c


hash_test: Hash_Test.c
	@gcc -o Hash_Test Hash_Test.c -lpthread -L. -lhash -Wall -std=gnu99

clean:
	rm -f hash_test libhash.so
