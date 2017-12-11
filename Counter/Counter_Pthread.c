#include "Counter_Pthread.h"

void counter_init(counter_t *c, int value) {
    c->value = value;
    pthread_mutex_init(&c->lock, NULL);
}

void counter_increment(counter_t *c){
    pthread_mutex_lock(&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
}

void counter_decrement(counter_t *c){
    pthread_mutex_lock(&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
}

int counter_get_value(counter_t *c){
    pthread_mutex_lock(&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return rc;
}