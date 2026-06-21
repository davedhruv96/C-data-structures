#include<stdio.h>
#include"linkedList.h"

int main(){
    printf("Initializing..\n");
    LinkedList* main = createList();
    prepend(main, 1);
    prepend(main, 2);
    printList(main);
    freeList(main);
    return 0;
}