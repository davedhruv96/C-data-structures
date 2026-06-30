#include "linkedList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  Node *prev;
  Node *next;
};

struct LinkedList {
  int size;
  Node *sentinel_head;
  Node *sentinel_tail;
};

LinkedList *createList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (!list) {
    return NULL;
  }
  Node *head = (Node *)malloc(sizeof(Node)); // sentinel head
  Node *tail = (Node *)malloc(sizeof(Node)); // sentinel tail
  head->next = tail;
  head->prev = NULL;
  tail->prev = head;
  tail->next = NULL;
  list->size = 0;
  list->sentinel_head = head;
  list->sentinel_tail = tail;
  return list;
}

void freeList(LinkedList *list) {
  if (!list) {
    return;
  }
  Node *nextPtr = list->sentinel_head->next;
  Node *freePtr;
  while (nextPtr != list->sentinel_tail) {
    freePtr = nextPtr;
    nextPtr = nextPtr->next;
    free(freePtr);
  }

  free(list->sentinel_head);
  free(list->sentinel_tail);
  free(list);
  return;
}

void printList(LinkedList *list) {
  if (!list) {
    return;
  }
  printf("[");
  Node *nextPtr = list->sentinel_head->next;
  while (nextPtr != list->sentinel_tail) {
    printf("%d", nextPtr->data);
    if (nextPtr->next != list->sentinel_tail) {
      printf(", ");
    }
    nextPtr = nextPtr->next;
  }
  printf("]\n");
}

int insert_start(LinkedList *list, int value) {
  if (!list) {
    return -1;
  }
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    return -1;
  }
  node->data = value;
  node->prev = list->sentinel_head;
  node->next = list->sentinel_head->next;

  list->sentinel_head->next->prev = node;
  list->sentinel_head->next = node;
  list->size++;
  return 0;
}

int insert_end(LinkedList *list, int value) {
  if (!list) {
    return -1;
  }

  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    return -1;
  }
  node->data = value;
  node->next = list->sentinel_tail;
  node->prev = list->sentinel_tail->prev;

  list->sentinel_tail->prev->next = node;
  list->sentinel_tail->prev = node;
  list->size++;
  return 0;
}

int insert_after(LinkedList *list, Node *target, int value) {
  if (!list || !target) {
    return -1;
  }

  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    return -1;
  }
  node->data = value;
  node->next = target->next;
  node->prev = target;

  target->next->prev = node;
  target->next = node;

  list->size++;
  return 0;
}

int delete_start(LinkedList *list) {
  if (!list) {
    return -1;
  }
  if (list->size == 0) {
    return 0;
  }
  Node *freePtr = list->sentinel_head->next;

  list->sentinel_head->next = list->sentinel_head->next->next;
  list->sentinel_head->next->prev = list->sentinel_head;
  list->size--;

  free(freePtr);
  return 0;
}

int delete_end(LinkedList *list) {
  if (!list) {
    return -1;
  }
  if (list->size == 0) {
    return 0;
  }
  Node *freePtr = list->sentinel_tail->prev;

  list->sentinel_tail->prev = list->sentinel_tail->prev->prev;
  list->sentinel_tail->prev->next = list->sentinel_tail;
  list->size--;

  free(freePtr);
  return 0;
}

int delete_after(LinkedList *list, Node *target) {
  if (!list) {
    return -1;
  }
  if (list->size == 0) {
    return 0;
  }
  Node *victim = target->next;
  if (victim == list->sentinel_tail) {
    return -1;
  }
  target->next = victim->next;
  victim->next->prev = target;

  list->size--;
  free(victim);
  return 0;
}

void reverse_list(LinkedList *list) {
  if (!list || list->size <= 1) {
    return;
  }

  Node *current = list->sentinel_head, *temp;

  while (current) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    // since we swapped next and prev pointer, the current->prev is now old
    // current->next
    current = current->prev;
  }
  temp = list->sentinel_head;
  list->sentinel_head = list->sentinel_tail;
  list->sentinel_tail = temp;
  return;
}

int is_empty(LinkedList *list) {
  if (list->size == 0) {
    return 1;
  } else {
    return 0;
  }
}

Node *find_value(LinkedList *list, int value) {
  if (!list || list->size == 0) {
    return NULL;
  }
  Node *current = list->sentinel_head->next;
  while (current != list->sentinel_tail && current->data != value) {
    current = current->next;
  }
  if (current == list->sentinel_tail) {
    return NULL;
  }
  return current;
}

int value_at(LinkedList *list, int index) {
  if (!list) { // error should be handled in a better way
    return -1;
  }
  int indexCount;
  Node *current;
  if (index > list->size / 2) {
    indexCount = list->size - 1;
    current = list->sentinel_tail->prev;
    while (current != list->sentinel_head && indexCount != index) {
      current = current->prev;
      indexCount--;
    }
    if (current != list->sentinel_head) {
      return current->data;
    }
  } else {
    indexCount = 0;
    current = list->sentinel_head->next;
    while (current != list->sentinel_tail && indexCount != index) {
      current = current->next;
      indexCount++;
    }
    if (current != list->sentinel_tail) {
      return current->data;
    }
  }
  return -1; // error should be handled in a better way
}

int delete_at(LinkedList *list, int index) {
  if (!list) {
    return -1;
  }
  if (index == 0) {
    if (delete_start(list) == 0) {
      return 0;
    } else {
      return -1;
    }
  } else if (index == list->size - 1) {
    if (delete_end(list) == 0) {
      return 0;
    } else {
      return -1;
    }
  }
  int indexCount;
  Node *current;
  if (index < list->size / 2) {
    current = list->sentinel_head->next;
    indexCount = 0;
    while (current != list->sentinel_tail && index != indexCount) {
      current = current->next;
      indexCount++;
    }
  } else {
    current = list->sentinel_tail->prev;
    indexCount = list->size - 1;
    while (current != list->sentinel_head && index != indexCount) {
      current = current->prev;
      indexCount--;
    }
  }
  if (index == indexCount) {
    current->next->prev = current->prev;
    current->prev->next = current->next;
    free(current);
    list->size--;
    return 0;
  } else {
    return -1;
  }
}

// void swap_nodes(LinkedList *list, int k) {
//   if (!list || list->size <= 1) {
//     return;
//   }
//   int loopCount = 1;
//   Node *node_to_swap_1 = NULL, *node_to_swap_2 = NULL;
//   Node *traverse = list->sentinel_head->next;
//   while (traverse != list->sentinel_tail) {
//     if (loopCount == k) {
//     }
//   }
// }
