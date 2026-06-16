#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createList()
{
    LinkedList *main = (LinkedList *)malloc(sizeof(LinkedList));
    if (!main)
    {
        printf("Error");
        return NULL;
    }
    main->head = NULL;

    return main;
}

void addData(LinkedList *main, int value)
{
    if (!main)
    {
        printf("Fatal error!\n");
        return;
    }
    else if (main->head == NULL)
    {
        Node *nextNode = (Node *)malloc(sizeof(Node));
        if (!nextNode)
        {
            printf("Memory Allocation failed!\n");
            return;
        }
        main->head = nextNode;
        nextNode->data = value;
        nextNode->next = NULL;
        printf("Data added succesfully!\n");
    }
    else
    {
        Node *nextNode = (Node *)malloc(sizeof(Node));
        if (!nextNode)
        {
            printf("Memory Allocation failed!\n");
            return;
        }
        Node *loopingNode;
        loopingNode = main->head;
        while (1)
        {
            if (loopingNode->next == NULL)
            {
                loopingNode->next = nextNode;
                nextNode->data = value;
                nextNode->next = NULL;
                printf("Data added succesfully!\n");
                break;
            }
            else
            {
                loopingNode = loopingNode->next;
            }
        }
        loopingNode == NULL;
    }
}

void destroyList(LinkedList *main)
{
    if (!main)
    {
        printf("Fatal error!\n");
        return;
    }
    Node* temp;
    Node *loopingNode;
    loopingNode=main->head;
    if(loopingNode == NULL){
        free(main);
        return;
    }
    while(loopingNode->next != NULL){
        temp = loopingNode;
        loopingNode = loopingNode->next;
        free(temp);
        
    }
    free(loopingNode);
    free(main);
}

int checkList(LinkedList* main,unsigned int numberOfNode, int value){
    if(!main){
        printf("Fatal!\n");
        return -1;
    }
    if(numberOfNode == 0){
        return -1;
    }
    
    Node* loopingNode = main->head;
    unsigned int count=1;
    while(loopingNode!=NULL){
        if(count == numberOfNode){
            if(value == loopingNode->data){
                return 1;
            }
            else{
                return 0;
            }
        }
        count++;
        loopingNode = loopingNode->next;
        
    }
    return -1;
}

void printList(LinkedList* main){
    if(!main){
        printf("Fatal!\n");
        return;
    }

    if(!(main->head)){
        printf("[]\n");
        return;
    }
    Node* loopingNode = main->head;
    printf("[");
    while(loopingNode){
        printf("%d, ",loopingNode->data);
        loopingNode = loopingNode->next;
    }
    printf("\b\b]\n");
}

int removeNthNode(LinkedList* main, int n){
    if(!main){
        printf("Fatal!\n");
        return -1;
    }
    int counter = 1;
    Node *loopingNode, *prevNode;
    prevNode = NULL;
    loopingNode = main->head;
    if(!main->head){
        printf("No Nodes found!\n"); 
        return -1;
    }
    while(loopingNode){
        if(counter == n){
            if(counter == 1){
                main->head = main->head->next;
                free(loopingNode);
                printf("Succesfully removed 1st node!\n");
                return 1;
            }
            prevNode->next = loopingNode->next;
            free(loopingNode);
            printf("Succesfully removed %dth node!\n",n);
            return 1;
        }
        prevNode = loopingNode;
        loopingNode = loopingNode->next;

        counter++;
    }
    printf("Error!\n");
    return -1;
}

int removeAllOccurenceOfValue(LinkedList* main, int value){
    if(!main){
        printf("Fatal!\n");
        return -1;
    }
    if(!main->head){
        printf("No Nodes Found!\n");
        return -1;
    }
    Node *loopingNode, *prevNode;
    prevNode = NULL;
    loopingNode = main->head;
    while(loopingNode){
        if(loopingNode->data == value){
            if(loopingNode == main->head){
                main->head = main->head->next;
                free(loopingNode);
                loopingNode = main->head;
            }
            else{
                prevNode->next = loopingNode->next;
                free(loopingNode);
                loopingNode = prevNode->next;
            }
        }
        else{
            prevNode = loopingNode;
            loopingNode = loopingNode->next;
        }
        
    }
    return 1;
}