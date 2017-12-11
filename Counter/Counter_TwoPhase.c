#include "Counter_TwoPhase.h"

void counter_init(counter_t *c, int value) {
    c->value = value;
    two_phase_init(&c->lock);
}

void counter_increment(counter_t *c){
    two_phase_acquire(&c->lock);
    c->value++;
    two_phase_release(&c->lock);
}

void counter_decrement(counter_t *c){
    two_phase_acquire(&c->lock);
    c->value--;
    two_phase_release(&c->lock);
}

int counter_get_value(counter_t *c){
    two_phase_acquire(&c->lock);
    int rc = c->value;
    two_phase_release(&c->lock);
    return rc;
}