#include "monty.h"

/**
 * _pall - print out all the elements of a stack
 * @head: pointer to the head of the stack
 * @count: the number of the line
 * Return: void
*/

void _pall(stack_t **head, unsigned int count)
{
	stack_t *pointer;
	(void)count;/*this is used when we are not using a function parameter*/

	pointer = *head;
	do {
	printf("%d\n", pointer->n);
	pointer = pointer->next;
	} while (pointer);
}
