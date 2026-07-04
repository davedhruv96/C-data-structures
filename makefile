LINKEDLIST_DOUBLE = LinkedList/Doubly-Linked-List
LINKEDLIST_SINGLE = LinkedList/Singly-Linked-List
STACK_LL = Stack/linked_list

doubly-ll:
	make -C $(LINKEDLIST_DOUBLE)

singly-ll:
	make -C $(LINKEDLIST_SINGLE)

stack_linkedlist:
	make -C $(STACK_LL)

clean:
	make -C $(LINKEDLIST_DOUBLE) clean;
	make -C $(LINKEDLIST_SINGLE) clean;
	make -C $(STACK_LL) clean;
