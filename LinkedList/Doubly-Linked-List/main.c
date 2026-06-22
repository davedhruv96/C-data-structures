#include<stdio.h>
#include"linkedList.h"

int main(){
    printf("Initializing..\n");
    LinkedList* main = createList();
    insert_start(main, 1);
    insert_end(main, 2);
    printList(main);
    freeList(main);
    return 0;
}