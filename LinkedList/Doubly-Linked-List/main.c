#include "linkedList.h"
#include <stdio.h>

int main() {
  printf("Initializing..\n");
  LinkedList *main = createList();
  insert_start(main, 1);
  insert_end(main, 2);
  insert_start(main, 5);
  printf("%d\n", value_at(main, 0));
  insert_start(main, 3);
  printList(main);
  reverse_list(main);
  printList(main);

  printf("%d\n", value_at(main, 0));
  freeList(main);
  return 0;
}
