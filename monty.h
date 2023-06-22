#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/*actions.c*/
void add_queue(stack_t **new_node, unsigned int _line);
void push(stack_t **new_node, unsigned int _line);
void pall(stack_t **stack, unsigned int _line);
void pop(stack_t **stack, unsigned int _line);
void pint(stack_t **stack, unsigned int _line);

/*error.c*/
void error_1(unsigned int error_code, ...);
void error_2(unsigned int error_code, ...);

/*files.c*/
void opfile(char *file_name);
void r_file(FILE *fd);
int int_line(char *string, int _line, int format);

/*functions.c*/
void swap(stack_t **stack, unsigned int _line);
void nop(stack_t **stack, unsigned int _line);

/*nodes.c*/
stack_t *new_node(int n);
void free_node(void);

/*operations.c*/
void add(stack_t **stack, unsigned int _line);
void sub(stack_t **stack, unsigned int _line);
void div_(stack_t **stack, unsigned int _line);
void mult(stack_t **stack, unsigned int _line);

/*search_find.c*/
void search_func(char *opcode, char *cmd, int _line, int format);
void find_func(op_func f, char *op_code, char *cmd, int _line, int format);


#endif /*_MAIN_H*/
