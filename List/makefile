all: liblist.so list_test
liblist.so: List_Lock.c spinlock.c List_Lock.h spinlock.h
	@gcc -shared -fPIC -o liblist.so List_Lock.c spinlock.c List_Lock.h spinlock.h


list_test: List_Test.c
	@gcc -o list_test List_Test.c -lpthread -L. -llist -Wall -std=gnu99

clean:
	rm -f liblist.so list_test
