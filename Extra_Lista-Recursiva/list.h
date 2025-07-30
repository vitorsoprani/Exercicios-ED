#ifndef _LIST_H
#define _LIST_H

// opace definition of the "List" type
typedef struct list List;

// Initialize a empty list
List* list_init();

// Insert a new element on the end of the list
List* list_append(List* list,
                  void* data,
                  void(print*)(void*),
                  int(compare*)(void* data, void* key),
                  void(destroy*)(void* data));

// Removed the element that corresponds to the given key
List* list_remove(List* list, void* key);

void list_print(List* list);

// Dealocate the list memory (Not the items)
List* list_destroy(List* list);

// Dealocate the items in the list, returning a empty list
List* list_destroyItems(List* list);

// Returns the element that corresponds to the given key
void* list_searchElement(List* list, void* key);

// Returns the cell containing the elemen(used in other functions)
static List* list_searchCell(List* list, void* key);

#endif //_LIST_H
