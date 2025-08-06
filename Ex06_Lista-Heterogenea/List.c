#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "List.h"

struct cell {
    void* data;
    char* type;
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
        free(cell_GetType(c->prev));
        free(c->prev);
    }
    free(cell_GetType(c));
    free(c);

    free(l);
}

void list_Insert(List* l, void* data, void (*print) (void* data), char* type) {
    assert(l);
    assert(data);

    Cell* new = (Cell*)malloc(sizeof(Cell));

    new->data = data;
    new->type = strdup(type);
    new->print = print;
    new->next = NULL;

    if (l->first == NULL) {
        new->prev = NULL;
        l->first = l->last = new;
        return;
    }

    new->prev = l->last;
    l->last->next = new;
    l->last = new;
}

Cell* list_Search(List* l, int (*compare) (void* data, void* key), char* type, void* key) {
    assert(l);

    Cell* c = l->first;

    while (c != NULL) {
        if (strcmp(cell_GetType(c), type) != 0) {
            c = c->next;
            continue;
        }
        if (compare(cell_GetData(c), key)) {
            return c;
        }
        
        c = c->next;
    }
    return c;
}

Cell* list_GetCellByIndex(List* l, int idx) {
    assert(l);

    Cell* cur = l->first;
    for (int i = 0; cur != NULL && i < idx; i++) {
        cur = cur->next;
    }

    return cur;
}

char* cell_GetType(Cell* c) {
    assert(c);

    return c->type;
}

Cell* cell_GetNext(Cell* c) {
    assert(c);

    return c->next;
}

void* cell_GetData(Cell* c) {
    assert(c);

    return c->data;
}

void* list_Remove(List* l, int (*compare) (void* data, void* key), char* type, void* key) {
    Cell* c = list_Search(l, compare, type, key);
    if (c == NULL)
        return c;
    
    void* d = cell_GetData(c);
    
    if (c->prev != NULL)
        c->prev->next = c->next;
    else
        l->first = c->next;
    if (c->next != NULL)
        c->next->prev = c->prev;
    else
        l->last = c->prev;

    free(c->type);
    free(c);

    return d;
}

void list_Print(List* l) {
    assert(l);
    Cell* c = l->first;

    while (c) {
        c->print(c->data);
        c = c->next;
    }
}