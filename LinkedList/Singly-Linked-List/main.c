#include<stdio.h>
#include "linkedList.h"

int main(){
    LinkedList* list = createList();    
    addDataAtEnd(list,1);
    addDataAtEnd(list, 2);
    addDataAtEnd(list, 3);
    addDataAtEnd(list, 4);
    addDataAtEnd(list, 5);
    addDataAtEnd(list, 6);
    printf("%d\n",getValueAtNthNode(list, 5));
    // printList(list);
    // reverseList(list);
    // printList(list);
}