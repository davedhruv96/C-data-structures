LINKEDLIST_DOUBLE = LinkedList/Doubly-Linked-List
LINKEDLIST_SINGLE = LinkedList/Singly-Linked-List

doubly-linkedlist:
	make -C $(LINKEDLIST_DOUBLE)

singly-linkedlist:
	make -C $(LINKEDLIST_SINGLE)

clean:
	make -C $(LINKEDLIST_DOUBLE) clean
	make -C $(LINKEDLIST_SINGLE) clean