#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

typedef struct LinkedList LinkedList;



LinkedList* createList();

void freeList(LinkedList* list);

int prepend(LinkedList* list, int value);

void printList(LinkedList* list);

#endif