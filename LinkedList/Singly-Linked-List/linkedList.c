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

void addDataAtEnd(LinkedList *main, int value)
{
    if (!main)
    {
        printf("Fatal!\n");
        return;
    }
    Node *nextNode = malloc(sizeof(Node));
    if (!nextNode)
    {
        printf("Allocation Failed!\n");
        return;
    }
    nextNode->data = value;
    nextNode->next = NULL;
    if (!main->head)
    {
        main->head = nextNode;
    }
    else
    {
        Node *loopingNode = main->head;
        while (loopingNode->next)
        {
            loopingNode = loopingNode->next;
        }
        loopingNode->next = nextNode;
    }
    printf("Data(\"%d\") added succesfully to the end!\n", value);
}

void destroyList(LinkedList *main)
{
    if (!main)
    {
        printf("Fatal error!\n");
        return;
    }
    Node *loopingNode = main->head, *dummy;
    while (loopingNode)
    {
        dummy = loopingNode;
        loopingNode = loopingNode->next;
        free(dummy);
    }
    main->head = NULL; // dangling pointer fix
    free(main);
}

int checkList(LinkedList *main, unsigned int numberOfNode, int value)
{
    if (!main)
    {
        printf("Fatal!\n");
        return -1;
    }
    if (numberOfNode == 0)
    {
        return -1;
    }

    Node *loopingNode = main->head;
    unsigned int count = 1;
    while (loopingNode != NULL)
    {
        if (count == numberOfNode)
        {
            if (value == loopingNode->data)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        count++;
        loopingNode = loopingNode->next;
    }
    return -1;
}

void printList(LinkedList *main)
{
    if (!main)
    {
        printf("Fatal!\n");
        return;
    }

    if (!(main->head))
    {
        printf("[]\n");
        return;
    }
    Node *loopingNode = main->head;
    printf("[");
    while (loopingNode)
    {
        printf("%d, ", loopingNode->data);
        loopingNode = loopingNode->next;
    }
    printf("\b\b]\n");
}

int removeNthNode(LinkedList *main, int n)
{
    if (!main)
    {
        printf("Fatal!\n");
        return -1;
    }
    int counter = 1;
    Node *loopingNode, *prevNode;
    prevNode = NULL;
    loopingNode = main->head;
    if (!main->head)
    {
        printf("No Nodes found!\n");
        return -1;
    }
    while (loopingNode)
    {
        if (counter == n)
        {
            if (counter == 1)
            {
                main->head = main->head->next;
                free(loopingNode);
                printf("Succesfully removed 1st node!\n");
                return 0;
            }
            prevNode->next = loopingNode->next;
            free(loopingNode);
            printf("Succesfully removed %dth node!\n", n);
            return 0;
        }
        prevNode = loopingNode;
        loopingNode = loopingNode->next;

        counter++;
    }
    printf("Error!\n");
    return -1;
}

int removeAllOccurenceOfValue(LinkedList *main, int value)
{
    if (!main)
    {
        printf("Fatal!\n");
        return -1;
    }
    if (!main->head)
    {
        printf("No Nodes Found!\n");
        return -1;
    }
    Node *loopingNode, *prevNode;
    prevNode = NULL;
    loopingNode = main->head;
    while (loopingNode)
    {
        if (loopingNode->data == value)
        {
            if (loopingNode == main->head)
            {
                main->head = main->head->next;
                free(loopingNode);
                loopingNode = main->head;
            }
            else
            {
                prevNode->next = loopingNode->next;
                free(loopingNode);
                loopingNode = prevNode->next;
            }
        }
        else
        {
            prevNode = loopingNode;
            loopingNode = loopingNode->next;
        }
    }
    return 0;
}

int insertAtNthPos(LinkedList *main, int n, int value)
{
    if (!main)
    {
        printf("Fatal!\n");
        return -1;
    }

    if (n == 1)
    {
        if (!main->head)
        {
            addDataAtEnd(main, value);
            return 0;
        }
        else
        {
            Node *nextNode = malloc(sizeof(Node));
            nextNode->data = value;
            nextNode->next = main->head;
            main->head = nextNode;
            return 0;
        }
    }
    else
    {
        Node *loopingNode = main->head, *prevNode = NULL;
        int counter = 1;
        while (loopingNode)
        {
            if (counter == n)
            {
                Node *nextNode = malloc(sizeof(Node));
                nextNode->data = value;
                nextNode->next = loopingNode;
                prevNode->next = nextNode;
                return 0;
            }
            else
            {
                prevNode = loopingNode;
                loopingNode = loopingNode->next;
                counter++;
            }
        }
        if (counter == n)
        {
            printf("To insert data at end, use \"addDataAtEnd()\"\n");
        }
        else
        {
            printf("Linked List Nodes are %d and %d<%d\n", counter, counter, n);
        }

        return -1;
    }
}

int getListLength(LinkedList *main)
{
    if (!main)
    {
        printf("Fatal!\n");
        return -1;
    }
    if (!main->head)
    {
        return 0;
    }
    else
    {
        Node *loopingNode = main->head;
        int counter = 1;
        while (loopingNode->next)
        {
            counter++;
            loopingNode = loopingNode->next;
        }
        return counter;
    }
}

int getValueAtNthNode(LinkedList *main, int n)
{
    if (!main || !main->head)
    {
        printf("Fatal!\n");
        return -1;
    }
    if (n < 1)
    {
        printf("N:%d, cant be less than 1.", n);
        return -1;
    }
    else if (getListLength(main) < n)
    {
        printf("Number of nodes are less than %d.\n", n);
        return -1;
    }
    else
    {
        Node *loopingNode = main->head;
        int counter = 1;
        while (loopingNode)
        {
            if (counter == n)
            {
                return loopingNode->data;
            }
            counter++;
            loopingNode = loopingNode->next;
        }
        printf("Error!\n");
        return -1;
    }
}

int reverseList(LinkedList *main)
{
    if (!main)
    {
        printf("Fatal!\n");
        return -1;
    }
    if(!main->head){
        return 1;
    }
    if(!main->head->next){
        return 1;
    }
    Node* prevNode = main->head, *currNode = main->head->next;
    if(!main->head->next->next){
        prevNode->next = NULL;
        currNode->next = prevNode;
        main->head = currNode;
        return 1;
    }
    Node *nextNode;
    nextNode = currNode->next;
    if(!nextNode){
        
    }

    prevNode->next = NULL;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;
    nextNode = nextNode->next;
    while (nextNode)
    {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        nextNode = nextNode->next;
    }
    currNode->next = prevNode;
    main->head = currNode;
}