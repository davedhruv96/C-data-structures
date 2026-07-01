CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

execute: main.c ./lib/linked_list.c ./lib/arena.c
	$(CC) $(CFLAGS) -o execute main.c ./lib/linked_list.c ./lib/arena.c

clean: 
	rm -f execute