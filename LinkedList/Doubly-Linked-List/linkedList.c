#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include"linkedList.h"

struct Node{
    int data;
    Node* prev;
    Node* next;
};

struct LinkedList{
    int size;
    Node* sentinel_head;
    Node* sentinel_tail;
};


LinkedList* createList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if(!list){
        return NULL;
    }

    Node* head = (Node*)malloc(sizeof(Node));   //sentinel head
    Node* tail = (Node*)malloc(sizeof(Node));   // sentinel tail
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
    
    list->size = 0;
    list->sentinel_head = head;
    list->sentinel_tail = tail;
    return list;
}

void freeList(LinkedList* list){
    if(!list){
        return;
    }
    Node* nextPtr = list->sentinel_head->next;
    Node* freePtr;
    while(nextPtr!=list->sentinel_tail){
        freePtr = nextPtr;
        nextPtr = nextPtr->next;
        free(freePtr);
    }

    free(list->sentinel_head);
    free(list->sentinel_tail);
    free(list);
    return;
}

void printList(LinkedList* list){
    if(!list){
        return;
    }
    printf("[");
    Node* nextPtr = list->sentinel_head->next;
    while(nextPtr!=list->sentinel_tail){
        printf("%d",nextPtr->data);
        if(nextPtr->next!=list->sentinel_tail){
            printf(", ");
        }
        nextPtr = nextPtr->next;
    }
    printf("]\n");
}

int prepend(LinkedList* list, int value){
    if(!list){
        return -1;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->prev = list->sentinel_head;
    node->next = list->sentinel_head->next;

    list->sentinel_head->next->prev = node;
    list->sentinel_head->next = node;
    list->size++;
    return 0;
}