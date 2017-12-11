#include "spinlock.h"
#include "Counter_Spinlock.h"

void counter_init(counter_t *c, int value){
    c->value = value;
    spinlock_init(&(c->lock));
}

int counter_get_value(counter_t *c){
    spinlock_acquire(&(c->lock));
    int value = c->value;
    spinlock_release(&(c->lock));
    return value;
}

void counter_increment(counter_t *c){
    spinlock_acquire(&(c->lock));
    c->value++;
    spinlock_release(&(c->lock));
}

void counter_decrement(counter_t *c){
    spinlock_acquire(&(c->lock));
    c->value--;
    spinlock_release(&(c->lock));
}