#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

struct cell {
    void* data;
    void (*print) (void* data);

    Cell* next;
    Cell* prev;
};

struct list {
    Cell* first;
    Cell* last;
};

List* list_Init() {
    List* l = (List*)malloc(sizeof(List));
    assert(l);

    l->first = NULL;
    l->last = NULL;

    return l;
}

void list_Free(List* l) {
    assert(l);
    Cell* c = l->first;

    while (c->next != NULL) {
        c = c->next;
        free(c->prev);
    }

    free(c);

    free(l);
}

void list_Insert(List* l, void* data, void (*print) (void* data)) {
    assert(l);
    assert(data);

    Cell* new = (Cell*)malloc(sizeof(Cell));

    new->data = data;
    new->print = print;
    new->next = NULL;

    if (l->first == NULL) {
        new->prev = NULL;
        l->first = l->last = new;
        return;
    }

    l->last->next = new;
    l->last = new;
}

Cell* list_Search(List* l, int (*compare) (void* data, void* key));

void* list_Remove(List* l, int (*compare) (void* data, void* key));

void list_Print(List* l) {
    assert(l);
    Cell* c = l->first;

    while (c) {
        c->print(c->data);
        c = c->next;
    }
}