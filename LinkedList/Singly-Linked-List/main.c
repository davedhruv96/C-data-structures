#include "linkedList.h"

int main(){
    LinkedList* list = createList();    
    addData(list, 2);
    addData(list, 3);
    addData(list,4);
    printList(list);
    addData(list, 120);
    addData(list, 400);
    printList(list);
    removeNthNode(list, 5);
    printList(list);
    addData(list, 2);
    addData(list, 2);
    addData(list, 2);
    addData(list,2);
    printList(list);
    removeAllOccurenceOfValue(list, 2);
    printList(list);
}