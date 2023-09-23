#ifndef _MONTY_H_
#define _MONTY_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - stores argument, file and content
 * @file: the file
 * @content: line content
 * @arg: the argument
 * 
 * Description: stores the argument, file
 * and file content from the opcodes file
 */
typedef struct bus_s
{
	FILE *file;
	char *content;
	char *arg;
} bus_t;

extern bus_t bus;

void _push(stack_t **head, unsigned int count);
void _pall(stack_t **head, unsigned int count);
void _pint(stack_t **head, unsigned int count);
void _pop(stack_t **head, unsigned int count);
void _swap(stack_t **head, unsigned int count);
void _add(stack_t **head, unsigned int count);
void _nop(stack_t **head, unsigned int count);
void _sub(stack_t **head, unsigned int count);
void _mul(stack_t **head, unsigned int count);
void _div(stack_t **head, unsigned int count);
void _mod(stack_t **head, unsigned int count);
int execute(stack_t **head, unsigned int count, FILE *file, char *content);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void free_stack(stack_t *head);

#endif
