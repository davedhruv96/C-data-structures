#include<stddef.h>
#include<stdlib.h>
#include"linkedList.h"

struct Node{
    int data;
    Node* prev;
    Node* next;
};

struct LinkedList{
    int size;
    Node* head;
};


LinkedList* createList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if(!list){
        return NULL;
    }
    list->size = 0;
    list->head = NULL;
}

void freeList(LinkedList* list){
    if(!list){
        return;
    }
    Node* freePtr=list->head;
    Node* nextPtr = NULL;
    while(freePtr){
        nextPtr = freePtr->next;
        free(freePtr);
        freePtr = nextPtr;
    }
    free(list);
    return;
}