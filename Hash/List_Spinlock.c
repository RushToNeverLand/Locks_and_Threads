#include <stdio.h>
#include <string.h>
#include "List_Spinlock.h"

void list_init(list_t *list){
    list->head=NULL;
    spinlock_init(&(list->lock));
    // mutex_init(&(list->lock));
    // two_phase_init(&(list->lock));
    // pthread_mutex_init(&(list->lock),NULL);
}

void list_insert(list_t *list, unsigned int key){
    node_t *p = (node_t*)malloc(sizeof(node_t));
    if(p==NULL){
        perror("Error: Malloc for List faile!\n");
        return ;
    }
    spinlock_acquire(&(list->lock));
    // mutex_acquire(&(list->lock));
    // two_phase_acquire(&(list->lock));
    // pthread_mutex_lock(&(list->lock));
    p->key = key;
    p->next = list->head;
    list->head = p;
    spinlock_release(&(list->lock));
    // mutex_release(&(list->lock));
    // two_phase_release(&(list->lock));
    // pthread_mutex_unlock(&(list->lock));
}

void list_delete(list_t *list, unsigned int key){
    if (list->head == NULL){
        return;
    }
    spinlock_acquire(&(list->lock));
    // mutex_acquire(&(list->lock));
    // two_phase_acquire(&(list->lock));
    // pthread_mutex_lock(&(list->lock));
    node_t *current = list->head;
    node_t *last = NULL;
    while (current!=NULL){
        if (current->key == key){
            break;
        }
        last = current;
        current = current->next;
    }
    if (current!=NULL){
        if (last == NULL){
            list->head = list->head->next;
            free(current);
        }
        else{
            last->next = current->next;
            free(current);
        }
    }
    spinlock_release(&(list->lock));
    // mutex_release(&(list->lock));
    // two_phase_release(&(list->lock));
    // pthread_mutex_unlock(&(list->lock));
}

void *list_lookup(list_t *list, unsigned int key){
    if (list->head == NULL){
        return NULL;
    }
    spinlock_acquire(&(list->lock));
    // mutex_acquire(&(list->lock));
    // two_phase_acquire(&(list->lock));
    // pthread_mutex_lock(&(list->lock));
    node_t *current = list->head;
    while (current){
        if (current->key == key) {
		    spinlock_release(&(list->lock));
		    // mutex_release(&(list->lock));
		    // two_phase_release(&(list->lock));
		    // pthread_mutex_unlock(&(list->lock));
            return (void*)current;
        }
        current = current->next;
    }
    spinlock_release(&(list->lock));
    // mutex_release(&(list->lock));
    // two_phase_release(&(list->lock));
    // pthread_mutex_unlock(&(list->lock));
    return NULL;
}

void list_free(list_t *list) {
    spinlock_acquire(&(list->lock));
    // mutex_acquire(&(list->lock));
    // two_phase_acquire(&(list->lock));
    // pthread_mutex_lock(&(list->lock));
    if (list->head == NULL) {
        return;
    }
    node_t *index = list->head;
    while (index) {
        node_t *temp = index;
        index = index->next;
        free(temp);
    }
    spinlock_release(&(list->lock));
    // mutex_release(&(list->lock));
    // two_phase_release(&(list->lock));
    // pthread_mutex_unlock(&(list->lock));
}