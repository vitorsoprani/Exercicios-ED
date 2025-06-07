#ifndef _LIST_H
#define _LIST_H

typedef struct cell Cell;

typedef struct list List;

List* list_Init();

void list_Destroy(List* l);

void list_Insert(List* l, void* data, void (*print) (void* data), char* type);

Cell* list_Search(List* l, int (*compare) (void* data, void* key), char* type, void* key);

Cell* list_GetCellByIndex(List* l, int idx);

char* cell_GetType(Cell* c);

Cell* cell_GetNext(Cell* c);

void* cell_GetData(Cell* c);

void* list_Remove(List* l, int (*compare) (void* data, void* key), char* type, void* key);

void list_Print(List* l);

void list_Free(List* l);

#endif