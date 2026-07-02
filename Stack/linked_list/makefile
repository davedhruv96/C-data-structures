CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
operator_prec = ./operator_precedence.c

execute: main.c ./lib/stack.c ./lib/arena.c ./lib/parser.c
	$(CC) $(CFLAGS) -o execute main.c ./lib/stack.c ./lib/arena.c ./lib/parser.c

op_prec: operator_precedence/operator_precedence.c ./lib/mystring.c ./lib/parser.c ./lib/stack.c ./lib/arena.c 
	$(CC) $(CFLAGS) -o op_prec operator_precedence/operator_precedence.c ./lib/mystring.c ./lib/parser.c ./lib/stack.c ./lib/arena.c

clean: 
	rm -f execute
	rm -f operator_precedence/op_prec
