#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct
{
    Node* head;
} LinkedList;

LinkedList *createList();

void addData(LinkedList* list, int data);

void destroyList(LinkedList* main);

int checkList(LinkedList* main,unsigned int numberOfNode, int value); 
// return 1 if that numberedNode has "value". 0 if not and -1 if that numberedNode doesnt exist in the list
// There will also be returning -1 if there is a fatal error that mainList is somehow empty 

int removeNthNode(LinkedList* main, int n);

int removeAllOccurenceOfValue(LinkedList* main, int value);

void printList(LinkedList* main);


#endif