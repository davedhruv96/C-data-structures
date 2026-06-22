#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

typedef struct LinkedList LinkedList;



LinkedList* createList();

void freeList(LinkedList* list);

void printList(LinkedList* list);

int insert_start(LinkedList* list, int value);

int insert_end(LinkedList* list, int value);

int insert_after(LinkedList* list, Node* target, int value);


#endif