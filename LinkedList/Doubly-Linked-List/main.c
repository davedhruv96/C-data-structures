#include<stdio.h>
#include"linkedList.h"

int main(){
    printf("Initializing..\n");
    LinkedList* main = createList();
    insert_start(main, 1);
    insert_end(main, 2);
    insert_start(main, 5);
    insert_start(main, 3);
    printList(main);
    reverse_list(main);
    printList(main);
    freeList(main);
    return 0;
}